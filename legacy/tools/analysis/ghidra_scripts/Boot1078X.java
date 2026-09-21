import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import java.util.*;

public class Boot1078X extends GhidraScript {
    public void run() throws Exception {
        long a = 0x80001078L;
        Function f = getFunctionContaining(toAddr(a));
        println("===== DECOMPILE FUN_80001078 @ 0x80001078 =====");
        if (f != null) {
            DecompInterface di = new DecompInterface();
            di.openProgram(currentProgram);
            DecompileResults dr = di.decompileFunction(f, 200, monitor);
            if (dr != null && dr.decompileCompleted()) println(dr.getDecompiledFunction().getC());
        } else println("(no func)");
    }
}
