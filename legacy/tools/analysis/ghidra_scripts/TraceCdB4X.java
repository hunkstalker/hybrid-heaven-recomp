import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import ghidra.app.decompiler.*;
import java.util.*;

public class TraceCdB4X extends GhidraScript {
    private void refs(long target, String label) {
        ReferenceManager refMgr = currentProgram.getReferenceManager();
        println("=== REFS to " + label + " (0x" + Long.toHexString(target) + ") ===");
        ReferenceIterator refs = refMgr.getReferencesTo(toAddr(target));
        while (refs.hasNext()) {
            Reference r = refs.next();
            Address from = r.getFromAddress();
            Function f = getFunctionContaining(from);
            println(String.format("  from 0x%08X  type=%s  func=%s", from.getOffset(), r.getReferenceType(), f!=null?f.getName():"?"));
        }
    }
    public void run() throws Exception {
        refs(0x800CD4B0L, "0x800CD4B0");
        refs(0x800CD4D8L, "0x800CD4D8");
        // decompile the thread that reads 0x800cd4b0 or 0x800cd4d8 - FUN_80029fa0 callers (task poster)
        // find functions that reference 0x800CD4B0 and decompile
        ReferenceManager refMgr = currentProgram.getReferenceManager();
        DecompInterface di = new DecompInterface();
        di.openProgram(currentProgram);
        Set<Long> done = new HashSet<>();
        ReferenceIterator refs = refMgr.getReferencesTo(toAddr(0x800CD4B0L));
        while (refs.hasNext()) {
            Reference r = refs.next();
            Function f = getFunctionContaining(r.getFromAddress());
            if (f != null && !done.contains(f.getEntryPoint().getOffset())) {
                done.add(f.getEntryPoint().getOffset());
                println("===== DECOMPILE " + f.getName() + " =====");
                DecompileResults dr = di.decompileFunction(f, 90, monitor);
                if (dr != null && dr.decompileCompleted()) println(dr.getDecompiledFunction().getC());
                println();
            }
        }
    }
}
