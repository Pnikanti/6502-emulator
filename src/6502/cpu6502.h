#pragma once
#include <cstdint>
#include "memory.h"

class CPU6502 {
public:
    CPU6502(Memory* memory, int32_t cycles);
    void Reset();
    void Run();
    void SetMemory(int address, uint8_t data);
private:
    void RunInstruction(uint8_t instruction);
    uint8_t Step();
    void LDA_Immediate();
    void LDX_Immediate();
private:
    Memory* m_memory;
    int16_t m_programCounter;
    int8_t m_stackPointer;
    int8_t m_accumulator;
    int8_t m_registerX;
    int8_t m_registerY;

    // Emulator cycles
    int32_t m_cycles;

    // Processor status flags
    bool m_carry;
    bool m_zero;
    bool m_interruptDisable;
    bool m_decimalMode;
    bool m_break;
    bool m_overflow;
    bool m_negative;
};