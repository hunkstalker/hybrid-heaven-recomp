import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import java.util.*;

public class BoundsListX extends GhidraScript {
    public void run() throws Exception {
        long[] fns = {0x800329F0L, 0x800329f0L, 0x80032890L, 0x80032be0L, 0x800329f0L};
        FunctionManager fm = currentProgram.getFunctionManager();
        Set<Long> done = new HashSet<>();
        for (long a : fns) {
            Function f = fm.getFunctionContaining(toAddr(a));
            if (f != null && done.add(f.getEntryPoint().getOffset())) {
                println("0x" + Long.toHexString(a) + " -> " + f.getName() + " @0x" + Long.toHexString(f.getEntryPoint().getOffset()) + " size=0x" + Long.toHexString(f.getBody().getNumAddresses()));
            }
        }
    }
}
