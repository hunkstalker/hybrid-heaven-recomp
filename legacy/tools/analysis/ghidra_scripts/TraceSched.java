import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import ghidra.program.model.mem.*;
import ghidra.program.model.lang.*;
import java.util.*;

public class TraceSched extends GhidraScript {

    private void scanAllRefs(long target, String label) {
        Address a = toAddr(target);
        ReferenceManager refMgr = currentProgram.getReferenceManager();
        println("=== References to " + label + " (0x" + Long.toHexString(target) + ") ===");
        ReferenceIterator refs = refMgr.getReferencesTo(a);
        int cnt = 0;
        while (refs.hasNext()) {
            Reference r = refs.next();
            Address from = r.getFromAddress();
            Function f = getFunctionContaining(from);
            String fname = (f != null) ? f.getName() : "?";
            println(String.format("  from 0x%08X  type=%s  func=%s  (0x%08X)", from.getOffset(), r.getReferenceType(), fname, from.getOffset()));
            cnt++;
        }
        println("  total=" + cnt);
    }

    public void run() throws Exception {
        // 1) Who writes the pointer to the main queue (0x8004ab18)?
        scanAllRefs(0x8004AB18L, "0x8004AB18 (ptr to main q stored by main thread)");
        scanAllRefs(0x8004AB10L, "0x8004AB10 (arg of main thread)");

        // 2) References to the main queue itself
        scanAllRefs(0x8005BF30L, "0x8005BF30 main queue");

        // 3) Find data definitions: what labels exist around these addresses
        println("=== Labels near 0x8004AB00-0x8004AB40 ===");
        SymbolTable st = currentProgram.getSymbolTable();
        Address s = toAddr(0x8004AB00L);
        Address sEnd = toAddr(0x8004AB40L);
        SymbolIterator it = st.getSymbolIterator();
        while (it.hasNext()) {
            Symbol sym = it.next();
            long a = sym.getAddress().getOffset();
            if (a >= 0x8004AB00L && a < 0x8004AB40L)
                println("  " + sym.getName() + " @ 0x" + Long.toHexString(a));
        }

        // 4) List functions in the region around 0x8004A000-0x8004B000 (where scheduler may live)
        println("=== Functions 0x8004A000-0x8004B000 ===");
        FunctionManager fm = currentProgram.getFunctionManager();
        Address start = toAddr(0x8004A000L);
        Address end = toAddr(0x8004B000L);
        FunctionIterator fits = fm.getFunctions(start, true);
        while (fits.hasNext()) {
            Function f = fits.next();
            if (f.getEntryPoint().compareTo(end) < 0)
                println(String.format("  0x%08X  %s  (size=0x%X)", f.getEntryPoint().getOffset(), f.getName(), f.getBody().getNumAddresses()));
        }
    }
}
