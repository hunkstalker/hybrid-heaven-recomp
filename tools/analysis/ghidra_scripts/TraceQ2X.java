import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import java.util.*;

public class TraceQ2X extends GhidraScript {
    private void refs(long target, String label) {
        ReferenceManager refMgr = currentProgram.getReferenceManager();
        println("=== REFS to " + label + " (0x" + Long.toHexString(target) + ") ===");
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
        refs(0x800CD4B0L, "0x800CD4B0 (VI/event queue)");
        refs(0x800CD4D8L, "0x800CD4D8 (sched queue)");
        refs(0x8005C288L, "0x8005C288 (thread5 loop queue)");
        refs(0x8005C4B0L, "0x8005C4B0");
    }
}
