import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import java.util.*;

public class DecompChainX extends GhidraScript {
    public void run() throws Exception {
        long[] fns = { 0x8001ffacL, 0x80001fb4L, 0x8000290cL, 0x8001f204L, 0x80001454L, 0x80001bb0L, 0x800346c0L };
        DecompInterface di = new DecompInterface();
        di.openProgram(currentProgram);
        for (long a : fns) {
            Function f = getFunctionContaining(toAddr(a));
            if (f == null) { println("===== NO FUNC 0x" + Long.toHexString(a) + " ====="); continue; }
            println("===== DECOMPILE " + f.getName() + " @ 0x" + Long.toHexString(a) + " =====");
            DecompileResults dr = di.decompileFunction(f, 90, monitor);
            if (dr != null && dr.decompileCompleted())
                println(dr.getDecompiledFunction().getC());
            else
                println("(failed)");
            println();
        }
    }
}
