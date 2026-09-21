import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import java.util.*;

public class W3750X extends GhidraScript {
    public void run() throws Exception {
        ReferenceManager rm = currentProgram.getReferenceManager();
        println("=== REFS to 0x80037750 (DAT_80037750) ===");
        ReferenceIterator refs = rm.getReferencesTo(toAddr(0x80037750L));
        while (refs.hasNext()) {
            Reference r = refs.next();
            Function f = getFunctionContaining(r.getFromAddress());
            println(String.format("  from 0x%08X type=%s func=%s", r.getFromAddress().getOffset(), r.getReferenceType(), f!=null?f.getName():"?"));
        }
        // also DAT_80037730 and DAT_80037748 writers
        println("=== REFS to 0x80037748 (DAT_80037748) ===");
        refs = rm.getReferencesTo(toAddr(0x80037748L));
        while (refs.hasNext()) {
            Reference r = refs.next();
            Function f = getFunctionContaining(r.getFromAddress());
            println(String.format("  from 0x%08X type=%s func=%s", r.getFromAddress().getOffset(), r.getReferenceType(), f!=null?f.getName():"?"));
        }
    }
}
