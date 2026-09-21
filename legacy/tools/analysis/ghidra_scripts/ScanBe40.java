import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import java.util.*;

public class ScanBe40 extends GhidraScript {
    private void scanConst(long target) {
        println("=== scan code computing 0x" + Long.toHexString(target) + " ===");
        Listing listing = currentProgram.getListing();
        FunctionIterator fits = currentProgram.getFunctionManager().getFunctions(true);
        long hi = target >>> 16;
        int lo = (int)(target & 0xffff);
        int found = 0;
        while (fits.hasNext()) {
            Function f = fits.next();
            InstructionIterator iit = listing.getInstructions(f.getBody(), true);
            long luiVal = -1;
            while (iit.hasNext()) {
                Instruction ins = iit.next();
                String txt = ins.toString();
                if (txt.startsWith("lui")) {
                    try { int imm = ins.getScalar(1).getSignedValue(); luiVal = (imm << 16) & 0xffffffffL; }
                    catch (Exception e) { luiVal = -1; }
                } else if ((txt.startsWith("addiu") || txt.startsWith("ori")) && luiVal != -1) {
                    try { if (ins.getScalar(1).getSignedValue() == lo)
                        println(String.format("  %s @ 0x%08X  (lui hi=0x%X)", txt, ins.getAddress().getOffset(), luiVal));
                    } catch (Exception e) {}
                }
            }
        }
        println("  found=" + found);
    }
    public void run() throws Exception {
        scanConst(0x8005BE40L);
        scanConst(0x8005BEC8L);
    }
}
