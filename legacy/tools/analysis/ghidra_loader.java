import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressSet;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.Reference;
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;

public class ghidra_loader extends GhidraScript {
	private Address at(long off) {
		return currentProgram.getAddressFactory().getAddress("0x" + Long.toHexString(off));
	}

	public void run() throws Exception {
		Listing listing = currentProgram.getListing();
		// 1) functions in wider loader zone
		int nf = 0;
		println("--- funciones 0x80040000..0x80060000 ---");
		for (Function f : currentProgram.getFunctionManager().getFunctions(at(0x80040000L), true)) {
			long s = f.getEntryPoint().getOffset();
			if (s > 0x80060000L) break;
			println("  " + f.getName() + " @0x" + Long.toHexString(s));
			nf++;
		}
		println("funciones=" + nf);

		// 2) force disassemble 0x80048000..0x8005F000
		Address d0 = at(0x80048000L);
		Address d1 = at(0x8005F000L);
		AddressSet todo = new AddressSet(d0, d1.subtract(1));
		listing.clearCodeUnits(d0, d1.subtract(1), false);
		println("--- disassemble 0x80048000..0x8005F000 ---");
		int[] fed = null;
		try {
			Address cur = d0;
			while (cur.compareTo(d1) < 0) {
				boolean ok = disassemble(cur);
				if (!ok) cur = cur.add(4); else fed = new int[] { 1 };
				cur = cur.add(4);
			}
		} catch (Exception e) {
			println("  disasm exception: " + e);
		}
		println("disassemble done: " + (fed == null ? "0 sites" : "some ok"));

		// 3) find references to target strings
		long[] targets = { 0x8004CBE8L, 0x8004CC40L, 0x8004CBFCL, 0x8004CC1CL, 0x8004CC50L,
			0x8004D7E8L, 0x8004D840L, 0x8004D850L, 0x8004D7FCL, 0x8004D81CL, 0x8004D628L, 0x8004E228L };
		println("--- refs a strings loader ---");
		DecompInterface di = new DecompInterface();
		di.openProgram(currentProgram);
		java.util.List<Function> hits = new java.util.ArrayList<>();
		for (long t : targets) {
			for (Reference r : currentProgram.getReferenceManager().getReferencesTo(at(t))) {
				Address from = r.getFromAddress();
				println("  ref 0x" + Long.toHexString(t) + " <- 0x" + Long.toHexString(from.getOffset()));
				Function f = currentProgram.getFunctionManager().getFunctionContaining(from);
				if (f != null && !hits.contains(f)) hits.add(f);
			}
		}
		println("--- decompile ---");
		for (Function f : hits) {
			DecompileResults res = di.decompileFunction(f, 60, monitor);
			println("=== " + f.getName() + " @0x" + Long.toHexString(f.getEntryPoint().getOffset()));
			println(res.getDecompiledFunction().getC());
		}
	}
}