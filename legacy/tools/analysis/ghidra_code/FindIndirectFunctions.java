// FindIndirectFunctions.java — ejecuta el "Aggressive Instruction Finder" de Ghidra sobre el
// rango del fichero para descubrir funciones que el recursive-descent no alcanza (solo llamadas
// por puntero/jalr, p. ej. func_80379410 en el fichero 57).
//
// Se ejecuta como preScript (antes del análisis) o postScript; es idempotente.
//
// Uso:
//   -preScript FindIndirectFunctions.java <vram_hex> <size_hex>
//
// @category HybridHeaven

import ghidra.app.plugin.prototype.analysis.AggressiveInstructionFinderAnalyzer;
import ghidra.app.script.GhidraScript;
import ghidra.app.util.importer.MessageLog;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressSet;

public class FindIndirectFunctions extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        long base = currentProgram.getMemory().getMinAddress().getOffset();
        long size;
        if (args.length >= 2) {
            base = Long.parseLong(args[0].replace("0x", "").replace("0X", ""), 16);
            size = Long.parseLong(args[1].replace("0x", "").replace("0X", ""), 16);
        } else {
            size = currentProgram.getMemory().getMaxAddress().getOffset() - base + 1;
        }
        Address lo = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(base);
        Address hi = lo.add(size - 1);
        AddressSet set = new AddressSet(lo, hi);

        AggressiveInstructionFinderAnalyzer finder = new AggressiveInstructionFinderAnalyzer();
        boolean ok = finder.added(currentProgram, set, monitor, new MessageLog());
        println("FindIndirectFunctions: finder added=" + ok + " rango=0x"
                + Long.toHexString(base) + "+0x" + Long.toHexString(size));
    }
}
