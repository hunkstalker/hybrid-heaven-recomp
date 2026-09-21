import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import java.util.*;

public class FindSender extends GhidraScript {
    private final long[] SEND = { 0x80026300L, 0x80030A10L }; // osSendMesg, osJamMesg
    private final long MAIN_Q = 0x8005BF30L;

    public void run() throws Exception {
        SymbolTable st = currentProgram.getSymbolTable();
        ReferenceManager refMgr = currentProgram.getReferenceManager();
        for (long a : SEND) {
            Address fn = toAddr(a);
            println("=== references to FUN_0x" + Long.toHexString(a) + " (osSendMesg/osJamMesg) ===");
            ReferenceIterator refs = refMgr.getReferencesTo(fn);
            int cnt = 0;
            while (refs.hasNext()) {
                Reference r = refs.next();
                Address from = r.getFromAddress();
                Function f = getFunctionContaining(from);
                String fname = (f != null) ? f.getName() : "?";
                println(String.format("  caller 0x%08X func=%s type=%s", from.getOffset(), fname, r.getReferenceType()));
                cnt++;
                if (cnt > 60) break;
            }
        }
    }
}
