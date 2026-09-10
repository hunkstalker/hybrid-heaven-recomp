import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import java.util.*;

public class FindMainQ extends GhidraScript {
    private final long MAIN_Q = 0x8005BF30L;

    public void run() throws Exception {
        Address q = toAddr(MAIN_Q);
        Listing listing = currentProgram.getListing();
        // find references to the main queue address
        ReferenceManager refMgr = currentProgram.getReferenceManager();
        ReferenceIterator refs = refMgr.getReferencesTo(q);
        println("=== References to 0x8005BF30 ===");
        while (refs.hasNext()) {
            Reference r = refs.next();
            Address from = r.getFromAddress();
            Function f = getFunctionContaining(from);
            String fname = (f != null) ? f.getName() : "?";
            println(String.format("ref from 0x%08X  type=%s  func=%s", from.getOffset(), r.getReferenceType(), fname));
        }

        // Also look at what writes/reads the queue struct: scan for osSendMesg callers
        println("=== osSendMesg callers (who sends to queues) ===");
        SymbolIterator syms = currentProgram.getSymbolTable().getSymbolIterator();
        while (syms.hasNext()) {
            Symbol s = syms.next();
            String n = s.getName();
            if (n != null && (n.contains("osSendMesg") || n.contains("osJamMesg"))) {
                println("symbol: " + n + " @ " + s.getAddress());
            }
        }
    }
}
