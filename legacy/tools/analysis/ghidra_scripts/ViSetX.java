import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import java.util.*;

public class ViSetX extends GhidraScript {
    public void run() throws Exception {
        ReferenceManager rm = currentProgram.getReferenceManager();
        println("=== REFS to 0x8004aed0 (VI event struct) ===");
        ReferenceIterator refs = rm.getReferencesTo(toAddr(0x8004aed0L));
        while (refs.hasNext()) {
            Reference r = refs.next();
            Function f = getFunctionContaining(r.getFromAddress());
            println(String.format("  from 0x%08X type=%s func=%s", r.getFromAddress().getOffset(), r.getReferenceType(), f!=null?f.getName():"?"));
        }
        // list functions in region where osViSetEvent lives (VI/event mgmt)
        println("=== Functions 0x80034900-0x80034B00 ===");
        FunctionManager fm = currentProgram.getFunctionManager();
        Address start = toAddr(0x80034900L);
        Address end = toAddr(0x80034B00L);
        FunctionIterator it = fm.getFunctions(start, true);
        while (it.hasNext()) {
            Function f = it.next();
            if (f.getEntryPoint().compareTo(end) < 0)
                println(String.format("  0x%08X  %s  size=0x%X", f.getEntryPoint().getOffset(), f.getName(), f.getBody().getNumAddresses()));
        }
    }
}
