import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import java.util.*;

public class DecompLocX extends GhidraScript {
    public void run() throws Exception {
        long[] locs = { 0x80052094L, 0x80035288L, 0x80052060L, 0x80035260L, 0x80029fa0L, 0x80028a10L, 0x80031b60L };
        DecompInterface di = new DecompInterface();
        di.openProgram(currentProgram);
        for (long a : locs) {
            Function f = getFunctionContaining(toAddr(a));
            println("----- @0x" + Long.toHexString(a) + " containing=" + (f != null ? f.getName() + " @0x" + Long.toHexString(f.getEntryPoint().getOffset()) : "null"));
            if (f != null) {
                DecompileResults dr = di.decompileFunction(f, 90, monitor);
                if (dr != null && dr.decompileCompleted())
                    println(dr.getDecompiledFunction().getC());
                else
                    println("(failed)");
            }
            println();
        }
    }
}
