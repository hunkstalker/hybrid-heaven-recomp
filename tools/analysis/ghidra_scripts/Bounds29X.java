import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import java.util.*;

public class Bounds29X extends GhidraScript {
    public void run() throws Exception {
        FunctionManager fm = currentProgram.getFunctionManager();
        println("=== funcs 0x80029E00-0x8002A300 ===");
        FunctionIterator it = fm.getFunctions(toAddr(0x80029E00L), true);
        while (it.hasNext()) {
            Function f = it.next();
            if (f.getEntryPoint().getOffset() < 0x8002A300L)
                println(String.format("  0x%08X %s size=0x%X", f.getEntryPoint().getOffset(), f.getName(), f.getBody().getNumAddresses()));
        }
    }
}
