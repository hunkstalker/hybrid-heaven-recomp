import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import java.util.*;

public class FindCallersX extends GhidraScript {

    private void callers(long target, String label) {
        ReferenceManager refMgr = currentProgram.getReferenceManager();
        println("=== CALLERS of " + label + " (0x" + Long.toHexString(target) + ") ===");
        ReferenceIterator refs = refMgr.getReferencesTo(toAddr(target));
        int cnt = 0;
        while (refs.hasNext()) {
            Reference r = refs.next();
            Address from = r.getFromAddress();
            Function f = getFunctionContaining(from);
            String fname = (f != null) ? f.getName() : "?";
            println(String.format("  from 0x%08X  type=%s  func=%s", from.getOffset(), r.getReferenceType(), fname));
            cnt++;
        }
        println("  total=" + cnt);
    }

    private void refs(long target, String label) {
        ReferenceManager refMgr = currentProgram.getReferenceManager();
        println("=== REFS to " + label + " (0x" + Long.toHexString(target) + ") ===");
        ReferenceIterator refs = refMgr.getReferencesTo(toAddr(target));
        int cnt = 0;
        while (refs.hasNext()) {
            Reference r = refs.next();
            Address from = r.getFromAddress();
            Function f = getFunctionContaining(from);
            String fname = (f != null) ? f.getName() : "?";
            println(String.format("  from 0x%08X  type=%s  func=%s", from.getOffset(), r.getReferenceType(), fname));
            cnt++;
        }
        println("  total=" + cnt);
    }

    public void run() throws Exception {
        callers(0x8002bfa0L, "FUN_8002bfa0 (task send)");
        callers(0x800304f0L, "FUN_800304f0 (task send2)");
        callers(0x8002add0L, "FUN_8002add0 (setup)");
        callers(0x8002ac60L, "FUN_8002ac60 (scheduler setup)");
        // VI event / retrace handler - find who calls osSetEventMesg and the VI manager
        callers(0x8002fb60L, "osSetEventMesg");
        // main thread region: find function containing 0x8002aea0
        println("=== functions near 0x8002aea0 ===");
        FunctionManager fm = currentProgram.getFunctionManager();
        Function f = fm.getFunctionContaining(toAddr(0x8002aea0L));
        println("  containing=" + (f != null ? f.getName() + " @0x" + Long.toHexString(f.getEntryPoint().getOffset()) : "null"));
        Address start = toAddr(0x8002A000L);
        Address end = toAddr(0x8002C000L);
        FunctionIterator fits = fm.getFunctions(start, true);
        while (fits.hasNext()) {
            Function g = fits.next();
            if (g.getEntryPoint().compareTo(end) < 0)
                println(String.format("  0x%08X  %s  (size=0x%X)", g.getEntryPoint().getOffset(), g.getName(), g.getBody().getNumAddresses()));
        }
    }
}
