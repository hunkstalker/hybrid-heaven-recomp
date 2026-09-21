import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import java.util.*;

public class DecompSchedX extends GhidraScript {
    public void run() throws Exception {
        long[] fns = { 0x8002ac60L, 0x8002AEA0L, 0x800326f0L, 0x8002bfa0L, 0x800304f0L, 0x80001124L, 0x800011b0L };
        DecompInterface di = new DecompInterface();
        di.openProgram(currentProgram);
        for (long a : fns) {
            Function f = getFunctionContaining(toAddr(a));
            if (f == null) { println("===== NO FUNC 0x" + Long.toHexString(a) + " ====="); continue; }
            println("===== DECOMPILE " + f.getName() + " @ 0x" + Long.toHexString(a) + " =====");
            DecompileResults dr = di.decompileFunction(f, 90, monitor);
            if (dr != null && dr.decompileCompleted()) {
                println(dr.getDecompiledFunction().getC());
            } else {
                println("(decompile failed: " + (dr != null ? dr.getErrorMessage() : "null") + ")");
            }
            println();
        }
    }
}
