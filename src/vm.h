#ifndef VM_H
#define VM_H

#define REGS_AMMOUNT 4

#define R0(value) (((value) & 0xf00) >> 8 )
#define R1(value) (((value) & 0xf0) >> 4 )
#define R2(value) ((value) & 0xf)

#define IMM(value) ((value) & 0xff)

#include <cstdint>
#include <vector>


enum OPC: uint32_t{
	HALT = 0x0,
	LDI, 
	ADD, SUB,
	MUL, DIV,
	INC, DEC,
	AND, OR, NOT,
	CLR
};

// Memory of the virtual machine
struct Memory {
	uint32_t* mem;
	uint32_t regs[REGS_AMMOUNT] = {0};

	Memory() : mem(new uint32_t[1024*4]) {};
	void loadToMem(const std::vector<uint32_t>& program) {
		for (uint32_t i = 0; i < program.size(); ++i) { mem[i] = program.at(i); }
	}
};

class VM {
private:
	uint32_t pc_ = 0;
	Memory mem_;
	bool is_running_ = false;

private:
	uint32_t fetch();
	void execute(uint32_t opcode, uint32_t instr);

public:
	void start(const std::vector<uint32_t>& program);
	VM() = default;
};

#endif // !VM_H