#include <string>
#include "cpu6502.h"
#include "opcodes.h"
#include "memory.h"
#include "utils/log.h"

CPU6502::CPU6502(Memory* memory, uint32_t cycles) : m_memory(memory), m_cycles(cycles) {
    LOG(">> CPU created with " + std::to_string(MAX_MEMORY) + " bytes of memory");
}

void CPU6502::SetMemory(uint16_t address, uint8_t data) {
    m_memory->memory[address] = data;
}

uint8_t CPU6502::Step() {
    m_cycles--;
    return m_memory->memory[m_programCounter++];
}

void CPU6502::Reset() {
    m_programCounter = 0xFFFC;
    m_stackPointer = 0x0100;
    m_memory->Reset();
}

void CPU6502::Run() {
    while (m_cycles > 0)
    {
        // Get instruction from the Program Counter
        LOG(">> Program Counter\n Address: " + std::to_string(m_programCounter));
        uint8_t instruction = Step();
        LOG(">> Program Counter\n Instruction: " + std::to_string(instruction));
        RunInstruction(instruction);
    }
}

void CPU6502::RunInstruction(uint8_t instruction) {
    switch( instruction ) {
        case LDA_IMMEDIATE:
            LDA_Immediate();
            break;
        default:
            break;
    }
}

void CPU6502::LDA_Immediate() {
    m_accumulator = Step();

    m_zero = (m_accumulator == 0);
    // & is bitwise AND operator
    m_negative = (m_accumulator & 0b1000000) > 0;
    LOG(">> LDA\nvalue: " + std::to_string(m_accumulator) +"\nzero: " + std::to_string(m_zero) + "\nnegative: " + std::to_string(m_negative));
}

void CPU6502::LDX_Immediate() {
    m_registerX = Step();

    if (m_registerX == 0x0)
        m_zero = true;
    if (m_registerX & (0x8 << m_registerX))
        m_negative = true;
}