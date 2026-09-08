import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Data;
import ghidra.program.model.listing.DataIterator;
import ghidra.program.model.listing.Function;
import ghidra.program.model.symbol.Reference;
import java.io.File;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.TreeSet;
import java.util.regex.Pattern;

public class ghidra_recon extends GhidraScript {
	private static final String OUT = "/app/hybrid-heaven-recomp/work/scratch/recon.txt";

	private static final String[][] PATT = {
		{ "seginfo",  "seginfo" },
		{ "romNo",    "romNo\\[" },
		{ "nisitenma","(?i)Nisitenma" },
		{ "func_map", "(?i)func_map|function_map" },
		{ "ucode",    "(?i)ucode|\\basp\\b|_audio|audio" },
	};

	public void run() throws Exception {
		PrintWriter pw = new PrintWriter(new File(OUT));
		DataIterator it = currentProgram.getListing().getDefinedData(true);
		int count = 0;
		List<Pattern> pats = new ArrayList<Pattern>();
		for (String[] p : PATT) pats.add(Pattern.compile(p[1]));

		// bucket: [patternIndex -> list of (addr,text)]
		List<List<String[]>> buckets = new ArrayList<List<String[]>>();
		for (int i = 0; i < PATT.length; i++) buckets.add(new ArrayList<String[]>());

		while (it.hasNext()) {
			Data d = it.next();
			count++;
			if (!d.hasStringValue()) continue;
			String s = String.valueOf(d.getValue());
			if (s == null) continue;
			for (int i = 0; i < pats.size(); i++) {
				if (pats.get(i).matcher(s).find()) {
					buckets.get(i).add(new String[] { d.getAddress().toString(), s });
					break;
				}
			}
		}
		pw.println("strings checked: " + count);
		for (int i = 0; i < PATT.length; i++) {
			List<String[]> items = buckets.get(i);
			pw.println("### " + PATT[i][0] + " (" + items.size() + ")");
			int shown = 0;
			for (String[] item : items) {
				if (shown++ >= 80) { pw.println("  ... (more)"); break; }
				TreeSet<String> rfuns = new TreeSet<String>();
				for (Reference r : currentProgram.getReferenceManager().getReferencesTo(
						currentProgram.getAddressFactory().getAddress(item[0]))) {
					Function f = currentProgram.getFunctionManager().getFunctionContaining(r.getFromAddress());
					if (f != null) rfuns.add(f.getName() + "@" + f.getEntryPoint());
				}
				pw.println("  " + item[0] + " " + item[1].substring(0, Math.min(item[1].length(), 90)).replace("\n", "\\n") + "  funcs=" + rfuns);
			}
		}
		pw.flush();
		pw.close();
		println("recon done -> " + OUT);
	}
}