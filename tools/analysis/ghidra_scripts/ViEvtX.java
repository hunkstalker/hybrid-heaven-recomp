import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import java.util.*;

public class ViEvtX extends GhidraScript {
    public void run() throws Exception {
        // decompile FUN_800349d0 (returns VI event struct)
        DecompInterface di = new DecompInterface();
        di.openProgram(currentProgram);
        long a = 0x800349d0L;
        Function f = getFunctionContaining(toAddr(a));
        println("===== DECOMPILE FUN_800349d0 @ 0x800349d0 =====");
        if (f != null) {
            DecompileResults dr = di.decompileFunction(f, 120, monitor);
            if (dr != null && dr.decompileCompleted()) println(dr.getDecompiledFunction().getC());
        } else println("(no func)");
        println();
        // callers of FUN_800349d0
        ReferenceManager rm = currentProgram.getReferenceManager();
        println("=== CALLERS of FUN_800349d0 ===");
        ReferenceIterator refs = rm.getReferencesTo(toAddr(a));
        while (refs.hasNext()) {
            Reference r = refs.next();
            Function c = getFunctionContaining(r.getFromAddress());
            println(String.format("  from 0x%08X type=%s func=%s", r.getFromAddress().getOffset(), r.getReferenceType(), c!=null?c.getName():"?"));
        }
    }
}
