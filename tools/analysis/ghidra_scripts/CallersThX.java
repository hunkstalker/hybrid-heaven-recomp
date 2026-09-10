import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import java.util.*;

public class CallersThX extends GhidraScript {
    private void callers(long target, String label) {
        ReferenceManager refMgr = currentProgram.getReferenceManager();
        println("=== CALLERS of " + label + " (0x" + Long.toHexString(target) + ") ===");
        ReferenceIterator refs = refMgr.getReferencesTo(toAddr(target));
        int cnt = 0;
        while (refs.hasNext()) {
            Reference r = refs.next();
            Address from = r.getFromAddress();
            Function f = getFunctionContaining(from);
            println(String.format("  from 0x%08X  type=%s  func=%s", from.getOffset(), r.getReferenceType(), f!=null?f.getName():"?"));
            cnt++;
        }
        println("  total=" + cnt);
    }
    public void run() throws Exception {
        callers(0x800011B0L, "FUN_800011b0");
        callers(0x8000121CL, "FUN_8000121c");
        callers(0x80001254L, "FUN_80001254");
        callers(0x8000126CL, "0x8000126c");
    }
}
