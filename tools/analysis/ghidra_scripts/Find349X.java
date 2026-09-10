import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import java.util.*;

public class Find349X extends GhidraScript {
    public void run() throws Exception {
        FunctionManager fm = currentProgram.getFunctionManager();
        // find function containing 0x800349D0
        Function f = fm.getFunctionContaining(toAddr(0x800349D0L));
        println("0x800349D0 containing=" + (f != null ? f.getName() + " @0x" + Long.toHexString(f.getEntryPoint().getOffset()) + " size=0x" + Long.toHexString(f.getBody().getNumAddresses()) : "null"));
        // list funcs around 0x80034840-0x80034C00
        println("=== funcs 0x80034840-0x80034C00 ===");
        FunctionIterator it = fm.getFunctions(toAddr(0x80034840L), true);
        while (it.hasNext()) {
            Function g = it.next();
            if (g.getEntryPoint().getOffset() < 0x80034C00L)
                println(String.format("  0x%08X %s size=0x%X", g.getEntryPoint().getOffset(), g.getName(), g.getBody().getNumAddresses()));
        }
    }
}
