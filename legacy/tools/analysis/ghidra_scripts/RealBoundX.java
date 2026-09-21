import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import ghidra.app.decompiler.*;
import java.util.*;

public class RealBoundX extends GhidraScript {
    public void run() throws Exception {
        FunctionManager fm = currentProgram.getFunctionManager();
        println("=== functions 0x800011B0-0x80001300 ===");
        FunctionIterator it = fm.getFunctions(toAddr(0x800011B0L), true);
        while (it.hasNext()) {
            Function f = it.next();
            if (f.getEntryPoint().getOffset() < 0x80001300L) {
                println(String.format("  0x%08X %s size=0x%X", f.getEntryPoint().getOffset(), f.getName(), f.getBody().getNumAddresses()));
            }
        }
        // decompile FUN_800011b0 fully
        DecompInterface di = new DecompInterface();
        di.openProgram(currentProgram);
        Function f = fm.getFunctionAt(toAddr(0x800011B0L));
        if (f != null) {
            println("===== DECOMPILE " + f.getName() + " =====");
            DecompileResults dr = di.decompileFunction(f, 120, monitor);
            if (dr != null && dr.decompileCompleted()) println(dr.getDecompiledFunction().getC());
        }
    }
}
