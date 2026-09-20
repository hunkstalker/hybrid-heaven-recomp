// SeedFunctionStarts.java — siembra inicios de función que el recursive-descent de Ghidra no
// alcanza en un fichero de código del Nisitenma (código solo referenciado por puntero/jalr, o
// funciones sin prólogo que empiezan justo tras un `jr $ra`).
//
// Candidatos (dentro de la región de texto [base, text_end)):
//   - prólogo `addiu $sp,$sp,-N`          (se descarta si es destino de rama interna)
//   - destino de `jal` dentro del fichero (fuerte)
//   - dirección tras `jr $ra` + delay-slot (se descarta si es rama interna)
//
// Uso (postScript, tras el análisis; antes de ExportSectionSyms):
//   -postScript SeedFunctionStarts.java <base_hex> <text_end_hex>
//
// @category HybridHeaven

import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressSpace;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionManager;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.symbol.Reference;
import ghidra.program.model.symbol.ReferenceManager;
import java.util.TreeSet;

public class SeedFunctionStarts extends GhidraScript {
    private boolean hasInternalBranchRef(ReferenceManager rm, Address addr) {
        for (Reference r : rm.getReferencesTo(addr)) {
            if (r.getReferenceType().isFlow() && !r.getReferenceType().isCall()) {
                return true;
            }
        }
        return false;
    }

    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        AddressSpace space = currentProgram.getAddressFactory().getDefaultAddressSpace();
        Memory mem = currentProgram.getMemory();
        FunctionManager fm = currentProgram.getFunctionManager();
        ReferenceManager rm = currentProgram.getReferenceManager();

        long base = currentProgram.getMemory().getMinAddress().getOffset();
        long textEnd = currentProgram.getMemory().getMaxAddress().getOffset() + 1;
        if (args.length >= 2) {
            base = Long.parseLong(args[0].replace("0x", "").replace("0X", ""), 16);
            textEnd = Long.parseLong(args[1].replace("0x", "").replace("0X", ""), 16);
        }

        TreeSet<Long> jalTargets = new TreeSet<>();
        TreeSet<Long> prologues = new TreeSet<>();
        TreeSet<Long> afterJr = new TreeSet<>();

        for (long a = base; a + 4 <= textEnd; a += 4) {
            Address addr = space.getAddress(a);
            int w;
            try {
                w = mem.getInt(addr);
            } catch (Exception e) {
                break;
            }
            long uw = w & 0xFFFFFFFFL;
            if (uw == 0x03E00008L) {                 // jr $ra
                long next = a + 8;
                if (next < textEnd) {
                    afterJr.add(next);
                }
            }
            if ((uw & 0xFFFF8000L) == 0x27BD8000L) { // addiu $sp,$sp,-N
                prologues.add(a);
            }
            if ((uw >>> 26) == 3) {                  // jal
                long target = ((uw & 0x03FFFFFFL) << 2) | ((a + 4) & 0xF0000000L);
                if (target >= base && target < textEnd) {
                    jalTargets.add(target);
                }
            }
        }

        int created = 0;
        created += createAll(space, fm, rm, jalTargets, true, base);
        created += createAll(space, fm, rm, prologues, false, base);
        created += createAll(space, fm, rm, afterJr, false, base);
        println("SeedFunctionStarts: base=0x" + Long.toHexString(base)
                + " textEnd=0x" + Long.toHexString(textEnd)
                + " jal=" + jalTargets.size() + " prologue=" + prologues.size()
                + " afterJr=" + afterJr.size() + " -> creadas=" + created);
    }

    private int createAll(AddressSpace space, FunctionManager fm, ReferenceManager rm,
                          TreeSet<Long> addrs, boolean isCall, long base) {
        int n = 0;
        for (long a : addrs) {
            Address addr = space.getAddress(a);
            if (fm.getFunctionContaining(addr) != null) {
                continue;
            }
            if (!isCall && hasInternalBranchRef(rm, addr)) {
                continue;
            }
            try {
                disassemble(addr);
                Function f = createFunction(addr, null);
                if (f != null) {
                    n++;
                }
            } catch (Exception e) {
                // dirección no desensamblable; se ignora
            }
        }
        return n;
    }
}
