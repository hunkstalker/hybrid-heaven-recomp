import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import java.util.*;

public class VSet2X extends GhidraScript {
    public void run() throws Exception {
        DecompInterface di = new DecompInterface();
        di.openProgram(currentProgram);
        long a = 0x800329f0L;
        Function f = getFunctionContaining(toAddr(a));
        println("===== DECOMPILE FUN_800329f0 (osViSetEvent?) @ 0x800329f0 =====");
        if (f != null) {
            DecompileResults dr = di.decompileFunction(f, 120, monitor);
            if (dr != null && dr.decompileCompleted()) println(dr.getDecompiledFunction().getC());
        } else println("(no func)");
        println();
        ReferenceManager rm = currentProgram.getReferenceManager();
        println("=== CALLERS of FUN_800329f0 ===");
        ReferenceIterator refs = rm.getReferencesTo(toAddr(a));
        while (refs.hasNext()) {
            Reference r = refs.next();
            Function c = getFunctionContaining(r.getFromAddress());
            println(String.format("  from 0x%08X type=%s func=%s", r.getFromAddress().getOffset(), r.getReferenceType(), c!=null?c.getName():"?"));
        }
    }
}
