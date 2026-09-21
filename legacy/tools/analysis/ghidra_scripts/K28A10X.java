import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import java.util.*;

public class K28A10X extends GhidraScript {
    public void run() throws Exception {
        long a = 0x80028a10L;
        Function f = getFunctionContaining(toAddr(a));
        println("===== func at 0x80028a10 =====");
        if (f != null) {
            println("name=" + f.getName() + " entry=0x" + Long.toHexString(f.getEntryPoint().getOffset()) + " size=0x" + Long.toHexString(f.getBody().getNumAddresses()));
            DecompInterface di = new DecompInterface();
            di.openProgram(currentProgram);
            DecompileResults dr = di.decompileFunction(f, 120, monitor);
            if (dr != null && dr.decompileCompleted()) println(dr.getDecompiledFunction().getC());
        } else println("(no func)");
    }
}
