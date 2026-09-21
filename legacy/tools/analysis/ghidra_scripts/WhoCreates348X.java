import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import java.util.*;

public class WhoCreates348X extends GhidraScript {
    public void run() throws Exception {
        ReferenceManager refMgr = currentProgram.getReferenceManager();
        println("=== callers of 0x80034840 (VI/timer thread) ===");
        ReferenceIterator refs = refMgr.getReferencesTo(toAddr(0x80034840L));
        while (refs.hasNext()) {
            Reference r = refs.next();
            Address from = r.getFromAddress();
            Function f = getFunctionContaining(from);
            println(String.format("  from 0x%08X func=%s type=%s", from.getOffset(), f!=null?f.getName():"?", r.getReferenceType()));
        }
        // check references to 0x80034840 as a PARAM (osCreateThread arg)
        println("=== refs to 0x800ce920 ===");
        refs = refMgr.getReferencesTo(toAddr(0x800CE920L));
        while (refs.hasNext()) {
            Reference r = refs.next();
            Address from = r.getFromAddress();
            Function f = getFunctionContaining(from);
            println(String.format("  from 0x%08X func=%s type=%s", from.getOffset(), f!=null?f.getName():"?", r.getReferenceType()));
        }
    }
}
