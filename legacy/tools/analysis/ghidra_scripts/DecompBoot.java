import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;

public class DecompBoot extends GhidraScript {
    private final long[] FNS = { 0x80000400L, 0x800011B0L };
    public void run() throws Exception {
        DecompInterface di = new DecompInterface();
        di.openProgram(currentProgram);
        for (long a : FNS) {
            Address fn = toAddr(a);
            Function f = getFunctionAt(fn);
            println("===== DECOMPILE 0x" + Long.toHexString(a) + " =====");
            if (f == null) { println("(no function at 0x"+Long.toHexString(a)+")"); continue; }
            DecompileResults res = di.decompileFunction(f, 400, monitor);
            if (res != null && res.decompileCompleted()) {
                println(res.getDecompiledFunction().getC());
            } else println("(decompile failed)");
        }
    }
}
