#include <iostream>

#include "vm.h"

int main(){
	VM vm;
	std::vector<uint32_t> program = { 
		0x1064, // ldi R0 100
		0x11C8, // ldi R1 200
		0x120A, // ldi R2 10
		0x2012, // add R0 R1 R2
		0x3301, // sub R3 R0 R1
		0x4333, // mul R3 R3 R3
		0x6300, // inc R3
		0x7200, // dec R2
		0x2223, // add R2 R2 R3
		0x7300, // dec R3
		0x2223, // add R2 R2 R3
		0x5002, // div R0 R0 R2
		/* 0xB000, // clr - clear all registers */
		0x0000 // halt
	};
	vm.start(program);
	return 0;
}