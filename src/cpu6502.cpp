#include <string>
#include "cpu6502.h"
#include "log.h"

void CPU6502::LDA(int8_t memory, AddressingMode::Mode addressingMode) {
    m_accumulator = memory;

    if (m_accumulator == 0)
        m_zero = true;
    if (m_accumulator & (8 << m_accumulator))
        m_negative = true;
    LOG(">> LDA\nm_zero: " + std::to_string(m_zero) + "\nm_negative: " + std::to_string(m_negative))
}

void CPU6502::LDX(int8_t memory, AddressingMode::Mode addressingMode) {
    m_registerX = memory;

    if (m_registerX == 0)
        m_zero = true;
    if (m_registerX & (8 << m_registerX))
        m_negative = true;
}