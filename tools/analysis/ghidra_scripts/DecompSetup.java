import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;

public class DecompSetup extends GhidraScript {
    private final long FN = 0x80001124L;
    public void run() throws Exception {
        DecompInterface di = new DecompInterface();
        di.openProgram(currentProgram);
        Address fn = toAddr(FN);
        Function f = getFunctionAt(fn);
        println("===== DECOMPILE FUN_80001124 (setup) =====");
        if (f == null) { println("(no function)"); return; }
        DecompileResults res = di.decompileFunction(f, 300, monitor);
        if (res != null && res.decompileCompleted()) {
            println(res.getDecompiledFunction().getC());
        } else println("(decompile failed)");
    }
}
