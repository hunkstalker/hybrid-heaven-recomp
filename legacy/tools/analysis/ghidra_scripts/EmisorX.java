import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import java.util.*;

public class EmisorX extends GhidraScript {

    private void disasmRange(long start, long end) {
        println("=== DISASM 0x" + Long.toHexString(start) + "-0x" + Long.toHexString(end) + " ===");
        Listing listing = currentProgram.getListing();
        Address a = toAddr(start);
        Address e = toAddr(end);
        while (a.compareTo(e) < 0) {
            Instruction ins = listing.getInstructionAt(a);
            if (ins != null) println(String.format("0x%08X  %s", a.getOffset(), ins.toString()));
            else println(String.format("0x%08X  (no ins)", a.getOffset()));
            a = a.add(4);
        }
    }

    private void refs(long target, String label) {
        ReferenceManager refMgr = currentProgram.getReferenceManager();
        println("=== REFS to " + label + " (0x" + Long.toHexString(target) + ") ===");
        ReferenceIterator refs = refMgr.getReferencesTo(toAddr(target));
        while (refs.hasNext()) {
            Reference r = refs.next();
            Address from = r.getFromAddress();
            Function f = getFunctionContaining(from);
            println(String.format("  from 0x%08X  type=%s  func=%s", from.getOffset(), r.getReferenceType(), f!=null?f.getName():"?"));
        }
    }

    private void fnAt(long a, String label) {
        FunctionManager fm = currentProgram.getFunctionManager();
        Function f = fm.getFunctionContaining(toAddr(a));
        println("=== enclosing func for " + label + " 0x" + Long.toHexString(a) + " ===");
        if (f != null) println("  " + f.getName() + " @0x" + Long.toHexString(f.getEntryPoint().getOffset()) + " size=0x" + Long.toHexString(f.getBody().getNumAddresses()));
        else println("  (none)");
    }

    public void run() throws Exception {
        fnAt(0x80052094L, "caller of FUN_8001ffac");
        fnAt(0x80035288L, "caller of FUN_80001fb4");
        disasmRange(0x80052060L, 0x800520D0L);
        disasmRange(0x80035250L, 0x800352D0L);
        // senders to thread-5 queues
        refs(0x8005C288L, "0x8005C288");
        refs(0x8005BE40L, "0x8005BE40");
        refs(0x8005C268L, "0x8005C268");
    }
}
