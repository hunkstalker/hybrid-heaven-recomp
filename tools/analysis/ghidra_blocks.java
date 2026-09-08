import ghidra.app.script.GhidraScript;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.mem.MemoryBlock;

public class ghidra_blocks extends GhidraScript {
	public void run() throws Exception {
		Memory mem = currentProgram.getMemory();
		for (MemoryBlock b : mem.getBlocks()) {
			println(String.format("%-16s start=0x%08X end=0x%08X size=0x%X rwx=%d%d%d init=%b",
				b.getName(), b.getStart().getOffset(), b.getEnd().getOffset(),
				b.getSize(), b.isRead() ? 1 : 0, b.isWrite() ? 1 : 0, b.isExecute() ? 1 : 0,
				b.isInitialized()));
		}
	}
}