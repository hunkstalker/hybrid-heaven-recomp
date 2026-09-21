import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import java.util.*;

public class TimerScanX extends GhidraScript {
    private final long TIMER_G = 0x8004AE60L;

    public void run() throws Exception {
        println("=== References to 0x8004AE60 (game timer global) ===");
        Address g = toAddr(TIMER_G);
        ReferenceManager refMgr = currentProgram.getReferenceManager();
        ReferenceIterator refs = refMgr.getReferencesTo(g);
        while (refs.hasNext()) {
            Reference r = refs.next();
            Address from = r.getFromAddress();
            Function f = getFunctionContaining(from);
            String fname = (f != null) ? f.getName() : "?";
            println(String.format("  ref from 0x%08X  type=%s  func=%s", from.getOffset(), r.getReferenceType(), fname));
        }

        println("=== Functions FUN_80031498 / FUN_80034560 / FUN_80031190 / FUN_8002bf90 ===");
        long[] addrs = { 0x80031498L, 0x80034560L, 0x80031190L, 0x8002bf90L, 0x80027f20L, 0x800317c0L };
        for (long a : addrs) {
            Function f = getFunctionAt(toAddr(a));
            println(String.format("  0x%08X -> %s", a, f != null ? f.getName() : "(no func)"));
        }

        println("=== Decompile FUN_80031498 (osSetTimer insert) ===");
        Function f98 = getFunctionAt(toAddr(0x80031498L));
        if (f98 != null) {
            println(decompile(f98));
        }

        println("=== Decompile FUN_80031190 (deadline compute) ===");
        Function f190 = getFunctionAt(toAddr(0x80031190L));
        if (f190 != null) {
            println(decompile(f190));
        }
    }
}
