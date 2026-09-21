import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import java.util.*;

public class ViScanX extends GhidraScript {

    private void decomp(long a, String label, DecompInterface di) {
        Function f = getFunctionContaining(toAddr(a));
        if (f == null) { println("===== NO FUNC " + label + " 0x" + Long.toHexString(a) + " ====="); return; }
        println("===== DECOMPILE " + f.getName() + " @ 0x" + Long.toHexString(a) + " =====");
        DecompileResults dr = di.decompileFunction(f, 120, monitor);
        if (dr != null && dr.decompileCompleted()) println(dr.getDecompiledFunction().getC());
        else println("(failed)");
        println();
    }

    public void run() throws Exception {
        // decompile candidate osViSetEvent functions
        DecompInterface di = new DecompInterface();
        di.openProgram(currentProgram);
        decomp(0x800349e0L, "FUN_800349e0", di);
        decomp(0x80034a10L, "FUN_80034a10", di);
        decomp(0x80034a70L, "FUN_80034a70", di);
        decomp(0x80034ab8L, "FUN_80034ab8", di);
        decomp(0x8002b2b0L, "FUN_8002b2b0 (sched submit?)", di);
    }
}
