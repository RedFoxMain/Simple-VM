#include "vm.h"
#include "dbm.h"

uint32_t VM::fetch() {
	return mem_.mem[pc_++];
}

void VM::execute(uint32_t opcode, uint32_t instr) {
	switch (opcode) {
		case OPC::HALT: is_running_ = false; break;
		case OPC::LDI:
			mem_.regs[R0(instr)] = IMM(instr);
			break;
		case OPC::ADD:
			mem_.regs[R0(instr)] = mem_.regs[R1(instr)] + mem_.regs[R2(instr)];
			break;
		case OPC::SUB:
			mem_.regs[R0(instr)] = mem_.regs[R1(instr)] - mem_.regs[R2(instr)];
			break;
		case OPC::MUL:
			mem_.regs[R0(instr)] = mem_.regs[R1(instr)] * mem_.regs[R2(instr)];
			break;
		case OPC::DIV:
			mem_.regs[R0(instr)] = mem_.regs[R1(instr)] / mem_.regs[R2(instr)];
			break;
		case OPC::INC: mem_.regs[R0(instr)]++; break;
		case OPC::DEC: mem_.regs[R0(instr)]--; break;
		case OPC::CLR: 
			for (uint32_t i = 0; i < 4; ++i) { mem_.regs[i] = 0; }
			break;
	}
}

void VM::start(const std::vector<uint32_t>& program) {
	mem_.loadToMem(program);
	printMem(mem_.mem, 0, program.size());
	is_running_ = true;
	while (is_running_) {
		uint32_t instr = fetch();
		execute((instr & 0xf000) >> 12, instr);
	}
	printRegs(mem_.regs);
}