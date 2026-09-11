import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import java.util.*;

public class Scan37750X extends GhidraScript {
    public void run() throws Exception {
        Listing listing = currentProgram.getListing();
        FunctionIterator fits = currentProgram.getFunctionManager().getFunctions(true);
        int found = 0;
        while (fits.hasNext()) {
            Function f = fits.next();
            InstructionIterator iit = listing.getInstructions(f.getBody(), true);
            long luiVal = -1;
            while (iit.hasNext()) {
                Instruction ins = iit.next();
                String txt = ins.toString();
                String mnem = ins.getMnemonicString();
                try {
                    if (mnem.equals("lui")) {
                        int imm = ins.getScalar(1).getSignedValue();
                        luiVal = (imm << 16) & 0xffffffffL;
                    } else if ((mnem.equals("addiu") || mnem.equals("ori") ||
                                mnem.equals("lw") || mnem.equals("sw") ||
                                mnem.equals("sh") || mnem.equals("sb") ||
                                mnem.equals("lhu") || mnem.equals("lbu")) && luiVal != -1) {
                        int imm = ins.getScalar(1).getSignedValue();
                        long eff = (luiVal + imm) & 0xffffffffL;
                        if (eff == 0x80037750L) {
                            Function cf = getFunctionContaining(ins.getAddress());
                            println(String.format("  %s @ 0x%08X (func=%s)  eff=0x%08X  lui=0x%X",
                                txt, ins.getAddress().getOffset(), cf!=null?cf.getName():"?", eff, luiVal));
                            found++;
                        }
                    }
                } catch (Exception e) {}
            }
        }
        println("  found=" + found);
    }
}
