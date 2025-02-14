#ifndef DBM_H
#define DBM_H

#include <iostream>
#include <cstdint>

void printRegs(uint32_t* regs) {
	for (uint32_t i = 0; i < 4; ++i) {
		std::cout << "R" << i << "=" << regs[i] << " ";
	}
	std::cout << "\n";
}
void printMem(uint32_t* mem, uint32_t from, uint32_t to) {
	for (uint32_t i = from; i < to; ++i) { 
		std::cout << "mem[" << i << "]=" << mem[i] << "\n"; 
	}
}

#endif // !DBM_H