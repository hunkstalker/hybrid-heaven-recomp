import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import java.util.*;

public class ListAroundX extends GhidraScript {
    private void list(long a, int n) {
        println("=== listing around 0x" + Long.toHexString(a) + " ===");
        Listing listing = currentProgram.getListing();
        Instruction it = listing.getInstructionAt(toAddr(a));
        if (it == null) { println("  NO INSTRUCTION at target; showing nearby"); }
        Address cur = toAddr(a - 0x20);
        for (int i = 0; i < n; i++) {
            Instruction ins = listing.getInstructionAt(cur);
            if (ins != null) {
                Function f = getFunctionContaining(cur);
                println(String.format("  0x%08X: %-12s %s   [func=%s]", cur.getOffset(), ins.getMnemonicString(), ins.toString(), f!=null?f.getName():"-"));
            } else {
                println(String.format("  0x%08X: (no instr)", cur.getOffset()));
            }
            cur = cur.add(4);
        }
    }
    public void run() throws Exception {
        list(0x80052094L, 22);
        println();
        list(0x80035288L, 22);
    }
}
