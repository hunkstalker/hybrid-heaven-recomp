import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import java.util.*;

public class InitX extends GhidraScript {
    public void run() throws Exception {
        long[] fns = {
            0x80001e70L, 0x80007b70L, 0x8001f204L, 0x80029fa0L, 0x80000934L
        };
        DecompInterface di = new DecompInterface();
        di.openProgram(currentProgram);
        for (long a : fns) {
            Function f = getFunctionContaining(toAddr(a));
            if (f == null) { println("===== NO FUNC 0x" + Long.toHexString(a) + " ====="); continue; }
            println("===== DECOMPILE " + f.getName() + " @ 0x" + Long.toHexString(a) + " =====");
            DecompileResults dr = di.decompileFunction(f, 90, monitor);
            if (dr != null && dr.decompileCompleted()) println(dr.getDecompiledFunction().getC());
            else println("(failed)");
            println();
        }
    }
}
