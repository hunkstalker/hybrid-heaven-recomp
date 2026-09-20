// ExportSectionSyms.java — exporta las funciones de un programa importado (un fichero de
// código del Nisitenma) como una sección de símbolos para N64Recomp.
//
// Pensado para el pipeline per-file (tools/ghidra_sections.py):
//   analyzeHeadless ... -import file_NN.bin -loader BinaryLoader -loader-baseAddr <vram>
//                        -postScript ExportSectionSyms.java <section> <src_rom> <size> <out>
//
// Escribe un TOML:
//   [[section]]
//   name = ".file_057"
//   rom  = 0x<src_rom>
//   vram = 0x<vram>
//   size = 0x<size>
//   functions = [ { name = "func_<vram>_<src_rom>", vram = ..., size = ... }, ... ]
//
// El nombre `func_<vram>_<src_rom>` es único a nivel global aunque dos ficheros compartan
// base de VRAM (overlays); el sufijo src_rom identifica el fichero.
//
// @category HybridHeaven

import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;
import ghidra.program.model.address.AddressSetView;
import java.io.File;
import java.io.FileWriter;

public class ExportSectionSyms extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length < 4) {
            println("uso: ExportSectionSyms <section> <src_rom_hex> <size_hex> <out_glob>");
            return;
        }
        String section = args[0];
        long srcRom = Long.parseLong(args[1].replace("0x", "").replace("0X", ""), 16);
        long size = Long.parseLong(args[2].replace("0x", "").replace("0X", ""), 16);
        File out = new File(args[3]);
        long base = currentProgram.getMemory().getMinAddress().getOffset();
        long limit = base + size;

        StringBuilder sb = new StringBuilder();
        sb.append("[[section]]\n");
        sb.append("name = \"").append(section).append("\"\n");
        sb.append(String.format("rom = 0x%X\n", srcRom));
        sb.append(String.format("vram = 0x%X\n", base));
        sb.append(String.format("size = 0x%X\n", size));
        sb.append("\nfunctions = [\n");

        int count = 0;
        FunctionIterator it = currentProgram.getFunctionManager().getFunctions(true);
        while (it.hasNext()) {
            Function f = it.next();
            long addr = f.getEntryPoint().getOffset();
            if (addr < base || addr >= limit) {
                continue;
            }
            AddressSetView body = f.getBody();
            long fsize = body.getNumAddresses();
            if (fsize <= 0) {
                continue;
            }
            // Recorta el cuerpo dentro de la sección (evita que un cuerpo invada el final).
            if (addr + fsize > limit) {
                fsize = limit - addr;
            }
            sb.append(String.format(
                "    { name = \"func_%08X_%06X\", vram = 0x%X, size = 0x%X },\n",
                addr, srcRom, addr, fsize));
            count++;
        }
        sb.append("]\n");

        try (FileWriter w = new FileWriter(out)) {
            w.write(sb.toString());
        }
        println("ExportSectionSyms: " + section + " -> " + count + " funciones en " + out.getPath());
    }
}
