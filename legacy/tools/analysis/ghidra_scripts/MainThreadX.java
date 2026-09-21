import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import ghidra.program.model.mem.*;
import java.util.*;

public class MainThreadX extends GhidraScript {

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

    private void disasmRange(long start, long end) {
        println("=== DISASM 0x" + Long.toHexString(start) + "-0x" + Long.toHexString(end) + " ===");
        Listing listing = currentProgram.getListing();
        Address a = toAddr(start);
        Address e = toAddr(end);
        while (a.compareTo(e) < 0) {
            Instruction ins = listing.getInstructionAt(a);
            if (ins != null) {
                println(String.format("0x%08X  %s", a.getOffset(), ins.toString()));
            } else {
                println(String.format("0x%08X  (no ins)", a.getOffset()));
            }
            a = a.add(4);
        }
    }

    private void decomp(long a, String label) {
        DecompInterface di = new DecompInterface();
        di.openProgram(currentProgram);
        Function f = getFunctionContaining(toAddr(a));
        if (f == null) { println("===== NO FUNC " + label + " 0x" + Long.toHexString(a) + " ====="); return; }
        println("===== DECOMPILE " + f.getName() + " @ 0x" + Long.toHexString(a) + " =====");
        DecompileResults dr = di.decompileFunction(f, 90, monitor);
        if (dr != null && dr.decompileCompleted()) println(dr.getDecompiledFunction().getC());
        else println("(failed)");
        println();
    }

    public void run() throws Exception {
        callers(0x8001ffacL, "FUN_8001ffac (calls task send)");
        callers(0x80001fb4L, "FUN_80001fb4 (calls task send2)");
        disasmRange(0x8002AEA0L, 0x8002B2B0L);
    }
}
