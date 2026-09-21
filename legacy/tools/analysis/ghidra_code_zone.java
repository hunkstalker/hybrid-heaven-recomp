import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressSet;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.listing.InstructionIterator;
import ghidra.program.model.listing.Listing;

public class ghidra_code_zone extends GhidraScript {
	public void run() throws Exception {
		Listing listing = currentProgram.getListing();
		// list functions in the loader region
		Address a0 = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(0x80047000L);
		Address a1 = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(0x8004E000L);
		FunctionIterator fit = currentProgram.getFunctionManager().getFunctions(a0, true);
		println("--- funciones en 0x80047000..0x8004E000 ---");
		int nf = 0;
		for (Function f : fit) {
			long s = f.getEntryPoint().getOffset();
			if (s > 0x8004E000L) break;
			println("  " + f.getName() + " @0x" + Long.toHexString(s) + " size=0x" + Long.toHexString(f.getBody().getNumAddresses()));
			nf++;
		}
		println("funciones=" + nf);

		// instructions around each loader string
		long[] marks = new long[] { 0x8004CBE8L, 0x8004CC40L, 0x8004D7E8L };
		for (long m : marks) {
			Address base = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(m - 0x40);
			InstructionIterator it = listing.getInstructions(base, true);
			println("--- instrucciones 0x" + Long.toHexString(m - 0x40) + "..+0x100 ---");
			int c = 0;
			for (Instruction in : it) {
				long off = in.getAddress().getOffset();
				if (off > m + 0x80) break;
				char tag = ' ';
				for (long mk : marks) if (off == mk) tag = '*';
				if (tag == '*' || c < 8)
					println("  " + (tag == '*' ? "*" : " ") + "0x" + Long.toHexString(off) + ": " + in.toString());
				c++;
			}
		}
	}
}