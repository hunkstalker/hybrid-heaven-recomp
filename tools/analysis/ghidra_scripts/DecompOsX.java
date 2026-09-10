import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import java.util.*;

public class DecompOsX extends GhidraScript {
    public void run() throws Exception {
        long[] fns = { 0x80000774L, 0x80000a5cL, 0x80000bf0L, 0x80000dc8L, 0x80032220L, 0x800346c0L };
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
        // who calls osCreateViManager (0x80032220)?
        ReferenceManager refMgr = currentProgram.getReferenceManager();
        println("=== callers of 0x80032220 (osCreateViManager) ===");
        ReferenceIterator refs = refMgr.getReferencesTo(toAddr(0x80032220L));
        while (refs.hasNext()) {
            Reference r = refs.next();
            Address from = r.getFromAddress();
            Function fc = getFunctionContaining(from);
            println(String.format("  from 0x%08X func=%s type=%s", from.getOffset(), fc!=null?fc.getName():"?", r.getReferenceType()));
        }
    }
}
