import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import java.util.*;

public class ChkCallersX extends GhidraScript {
    private void list(long a, int n) {
        println("=== listing around 0x" + Long.toHexString(a) + " ===");
        Listing listing = currentProgram.getListing();
        Address cur = toAddr(a - 0x20);
        for (int i = 0; i < n; i++) {
            Instruction ins = listing.getInstructionAt(cur);
            if (ins != null) {
                Function f = getFunctionContaining(cur);
                println(String.format("  0x%08X: %-12s %s  [func=%s]", cur.getOffset(), ins.getMnemonicString(), ins.toString(), f!=null?f.getName():"-"));
            } else {
                println(String.format("  0x%08X: (no instr)", cur.getOffset()));
            }
            cur = cur.add(4);
        }
    }
    public void run() throws Exception {
        list(0x80035D38L, 14);
        println();
        list(0x800362D8L, 14);
    }
}
