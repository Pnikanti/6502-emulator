#pragma once
#include <cstdint>
#include "memory.h"

class CPU6502 {
public:
    CPU6502(Memory* memory, uint32_t cycles);
    void Reset();
    void Run();
    void SetMemory(uint16_t address, uint8_t data);
private:
    void RunInstruction(uint8_t instruction);
    uint8_t Step();
    void LDA_Immediate();
    void LDX_Immediate();
private:
    Memory* m_memory;
    uint16_t m_programCounter;
    uint8_t m_stackPointer;
    uint8_t m_accumulator;
    uint8_t m_registerX;
    uint8_t m_registerY;

    // Emulator cycles
    uint32_t m_cycles;

    // Processor status flags
    bool m_carry;
    bool m_zero;
    bool m_interruptDisable;
    bool m_decimalMode;
    bool m_break;
    bool m_overflow;
    bool m_negative;
};