import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import java.util.*;

public class FindVSetX extends GhidraScript {
    public void run() throws Exception {
        // scan all instructions for writes to 0x8004ae80 (0x8004ae70+0x10) and 0x8004ae84 (+0x14)
        // and 0x8004aeb0/0x8004aeb4 (the second VI buffer)
        long[] targets = { 0x8004ae80L, 0x8004ae84L, 0x8004aeb0L, 0x8004aeb4L, 0x8004aed0L };
        Listing listing = currentProgram.getListing();
        ReferenceManager rm = currentProgram.getReferenceManager();
        for (long t : targets) {
            println("=== REFS to 0x" + Long.toHexString(t) + " ===");
            ReferenceIterator refs = rm.getReferencesTo(toAddr(t));
            int c = 0;
            while (refs.hasNext()) {
                Reference r = refs.next();
                Function f = getFunctionContaining(r.getFromAddress());
                println(String.format("  from 0x%08X type=%s func=%s", r.getFromAddress().getOffset(), r.getReferenceType(), f!=null?f.getName():"?"));
                c++;
            }
            println("  total=" + c);
        }
    }
}
