import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import java.util.*;

public class DecompSched2X extends GhidraScript {
    public void run() throws Exception {
        long[] fns = { 0x8002add0L, 0x8002ae20L, 0x8002ae64L, 0x80029fa0L };
        DecompInterface di = new DecompInterface();
        di.openProgram(currentProgram);
        for (long a : fns) {
            Function f = getFunctionContaining(toAddr(a));
            if (f == null) { println("===== NO FUNC 0x" + Long.toHexString(a) + " ====="); continue; }
            println("===== DECOMPILE " + f.getName() + " @ 0x" + Long.toHexString(a) + " =====");
            DecompileResults dr = di.decompileFunction(f, 90, monitor);
            if (dr != null && dr.decompileCompleted())
                println(dr.getDecompiledFunction().getC());
            else
                println("(failed)");
            println();
        }
        // who calls FUN_80029fa0 (task poster via global queue) and FUN_8002bfa0
        ReferenceManager refMgr = currentProgram.getReferenceManager();
        for (long t : new long[]{0x80029fa0L, 0x8002bfa0L, 0x800326d0L}) {
            println("=== callers of 0x" + Long.toHexString(t) + " ===");
            ReferenceIterator refs = refMgr.getReferencesTo(toAddr(t));
            while (refs.hasNext()) {
                Reference r = refs.next();
                Address from = r.getFromAddress();
                Function fc = getFunctionContaining(from);
                println(String.format("  from 0x%08X func=%s type=%s", from.getOffset(), fc!=null?fc.getName():"?", r.getReferenceType()));
            }
        }
    }
}
