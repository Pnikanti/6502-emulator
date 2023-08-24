#pragma once
#include <cstdint>

namespace AddressingMode {
    enum Mode {
        Immediate,
        ZeroPage,
        ZeroPageX,
        Absolute,
        AbsoluteX,
        AbsoluteY,
        IndirectX,
        IndirectY
    };
}


class CPU6502 {
public:
    void LDA(int8_t memory, AddressingMode::Mode addressingMode);
    void LDX(int8_t memory, AddressingMode::Mode addressingMode);
private:
    int16_t m_programCounter;
    int8_t m_stackPointer[256];
    int8_t m_accumulator;
    int8_t m_registerX;
    int8_t m_registerY;

    // Processor status flags
    bool m_carry;
    bool m_zero;
    bool m_interruptDisable;
    bool m_break;
    bool m_overflow;
    bool m_negative;
};