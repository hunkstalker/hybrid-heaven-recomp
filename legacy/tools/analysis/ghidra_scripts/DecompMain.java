import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;

public class DecompMain extends GhidraScript {
    private final long FN = 0x8002AEA0L;
    public void run() throws Exception {
        DecompInterface di = new DecompInterface();
        di.openProgram(currentProgram);
        Address fn = toAddr(FN);
        Function f = getFunctionAt(fn);
        println("===== DECOMPILE FUN_8002AEA0 (main thread) =====");
        if (f == null) { println("(no function)"); return; }
        DecompileResults res = di.decompileFunction(f, 500, monitor);
        if (res != null && res.decompileCompleted()) {
            String c = res.getDecompiledFunction().getC();
            println(c);
        } else println("(decompile failed)");
    }
}
