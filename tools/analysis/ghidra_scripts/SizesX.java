import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import java.util.*;

public class SizesX extends GhidraScript {
    public void run() throws Exception {
        long[] fns = { 0x8002bf90L, 0x8002bfa0L, 0x800304f0L, 0x800326f0L, 0x8001ffacL, 0x80001fb4L, 0x80001ffacL };
        for (long a : fns) {
            Function f = getFunctionContaining(toAddr(a));
            if (f == null) { println("0x" + Long.toHexString(a) + " -> NO FUNC"); continue; }
            println("0x" + Long.toHexString(a) + " -> " + f.getName() + " @0x" + Long.toHexString(f.getEntryPoint().getOffset()) + " size=0x" + Long.toHexString(f.getBody().getNumAddresses()));
        }
        // list functions 0x8002BF00-0x8002C100
        println("=== funcs 0x8002BF00-0x8002C100 ===");
        FunctionManager fm = currentProgram.getFunctionManager();
        FunctionIterator it = fm.getFunctions(toAddr(0x8002BF00L), true);
        while (it.hasNext()) {
            Function f = it.next();
            if (f.getEntryPoint().getOffset() < 0x8002C100L)
                println(String.format("  0x%08X %s size=0x%X", f.getEntryPoint().getOffset(), f.getName(), f.getBody().getNumAddresses()));
        }
        // also funcs 0x800326F0-0x80032780 and 0x800304F0
        println("=== funcs 0x800304F0-0x80030580 ===");
        it = fm.getFunctions(toAddr(0x800304F0L), true);
        while (it.hasNext()) {
            Function f = it.next();
            if (f.getEntryPoint().getOffset() < 0x80030580L)
                println(String.format("  0x%08X %s size=0x%X", f.getEntryPoint().getOffset(), f.getName(), f.getBody().getNumAddresses()));
        }
        println("=== funcs 0x800326F0-0x80032780 ===");
        it = fm.getFunctions(toAddr(0x800326F0L), true);
        while (it.hasNext()) {
            Function f = it.next();
            if (f.getEntryPoint().getOffset() < 0x80032780L)
                println(String.format("  0x%08X %s size=0x%X", f.getEntryPoint().getOffset(), f.getName(), f.getBody().getNumAddresses()));
        }
    }
}
