import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import java.util.*;

public class ExportFuncsX extends GhidraScript {
    public void run() throws Exception {
        FunctionManager fm = currentProgram.getFunctionManager();
        FunctionIterator it = fm.getFunctions(true);
        StringBuilder sb = new StringBuilder();
        int count = 0;
        while (it.hasNext()) {
            Function f = it.next();
            long addr = f.getEntryPoint().getOffset();
            long size = f.getBody().getNumAddresses();
            String name = f.getName();
            if (addr >= 0x80000400L && addr < 0x8004E5B40L) {
                sb.append(String.format("    { name = \"%s\", vram = 0x%X, size = 0x%X },\n", name, addr, size));
                count++;
            }
        }
        // write to a file next to the script
        java.io.File out = new java.io.File("/app/hybrid-heaven-recomp/work/ghidra_funcs.txt");
        java.io.FileWriter w = new java.io.FileWriter(out);
        w.write(sb.toString());
        w.close();
        println("Exported " + count + " functions to " + out.getAbsolutePath());
    }
}
