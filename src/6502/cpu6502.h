#pragma once
#include <cstdint>
#include "memory.h"

class CPU6502 {
public:
    CPU6502(Memory* memory, uint32_t cycles);
    void Reset();
    void Start();
    void Program(uint16_t address, uint16_t data);
private:
    uint16_t StepProgramCounter();
    void Execute(uint8_t instruction);
    void WriteMemory(uint16_t address, uint8_t data);
    void WriteMemory(uint16_t address, uint16_t data);
    uint16_t LoadMemory(uint8_t address);
    uint16_t LoadMemory(uint16_t address);
    // Instructions
    void LDA_IM();
    void LDA_ZP();
    void LDX_IM();
    void LDX_ZP();
    void JSR();
private:
    Memory* m_memory;
    uint16_t m_programCounter;
    uint8_t m_stackPointer;
    uint8_t m_accumulator;
    uint8_t m_registerX;
    uint8_t m_registerY;

    // CPU Emulator cycles
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