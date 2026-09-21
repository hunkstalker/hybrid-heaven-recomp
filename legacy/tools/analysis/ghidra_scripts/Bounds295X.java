import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import java.util.*;

public class Bounds295X extends GhidraScript {
    public void run() throws Exception {
        long[] fns = {0x800295d0L, 0x80029580L};
        for (long a : fns) {
            Function f = getFunctionContaining(toAddr(a));
            if (f != null) println("0x" + Long.toHexString(a) + " -> " + f.getName() + " @0x" + Long.toHexString(f.getEntryPoint().getOffset()) + " size=0x" + Long.toHexString(f.getBody().getNumAddresses()));
        }
    }
}
