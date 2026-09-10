import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import java.util.*;

public class FindCall2X extends GhidraScript {
    private void callers(long target, String label) {
        ReferenceManager refMgr = currentProgram.getReferenceManager();
        println("=== CALLERS of " + label + " (0x" + Long.toHexString(target) + ") ===");
        ReferenceIterator refs = refMgr.getReferencesTo(toAddr(target));
        int cnt = 0;
        while (refs.hasNext()) {
            Reference r = refs.next();
            Address from = r.getFromAddress();
            Function f = getFunctionContaining(from);
            String fname = (f != null) ? f.getName() : "?";
            println(String.format("  from 0x%08X  type=%s  func=%s", from.getOffset(), r.getReferenceType(), fname));
            cnt++;
        }
        println("  total=" + cnt);
    }
    public void run() throws Exception {
        callers(0x8001ffacL, "FUN_8001ffac (task poster)");
        callers(0x80001fb4L, "FUN_80001fb4 (task poster2)");
        callers(0x800290cL, "FUN_8000290c");
        callers(0x80032660L, "FUN_80032660 (__osSetThreadPri?)");
        callers(0x80034400L, "FUN_80034400 (task exec?)");
    }
}
