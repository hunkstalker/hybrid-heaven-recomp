import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import java.util.*;

public class ListFnsX extends GhidraScript {
    public void run() throws Exception {
        long[][] ranges = {
            {0x80052000L, 0x80052600L},
            {0x80035000L, 0x80035600L},
            {0x8001fc00L, 0x80020400L},
            {0x80001000L, 0x80003000L},
        };
        FunctionManager fm = currentProgram.getFunctionManager();
        for (long[] r : ranges) {
            println("=== Functions " + Long.toHexString(r[0]) + "-" + Long.toHexString(r[1]) + " ===");
            FunctionIterator fits = fm.getFunctions(toAddr(r[0]), true);
            while (fits.hasNext()) {
                Function f = fits.next();
                if (f.getEntryPoint().compareTo(toAddr(r[1])) < 0)
                    println(String.format("  0x%08X  %s  (size=0x%X)", f.getEntryPoint().getOffset(), f.getName(), f.getBody().getNumAddresses()));
            }
        }
    }
}
