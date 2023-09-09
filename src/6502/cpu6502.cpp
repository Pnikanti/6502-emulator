#include <string>
#include "cpu6502.h"
#include "opcodes.h"
#include "memory.h"
#include "utils/log.h"

CPU6502::CPU6502(Memory* memory, uint32_t cycles) : m_memory(memory), m_cycles(cycles)
{
    LOG(">> CPU created with " + std::to_string(MAX_MEMORY) + " bytes of memory");
}

void CPU6502::Program(uint16_t address, uint16_t data)
{
    m_memory->memory[address] = data;
}

void CPU6502::WriteMemory(uint16_t address, uint8_t data)
{
    m_cycles--;
    m_memory->memory[address] = data;
}

void CPU6502::WriteMemory(uint16_t address, uint16_t data)
{
    m_cycles -= 2;
    m_memory->memory[address] = data;
}

uint16_t CPU6502::StepProgramCounter()
{
    m_cycles--;
    return m_memory->memory[m_programCounter++];
}

uint16_t CPU6502::LoadMemory(uint8_t address)
{
    m_cycles--;
    return m_memory->memory[address];
}

uint16_t CPU6502::LoadMemory(uint16_t address)
{
    m_cycles -= 2;
    return m_memory->memory[address];
}

void CPU6502::Reset()
{
    m_programCounter = 0xFFFC;
    m_stackPointer = 0x0100;
    m_memory->Reset();
}

void CPU6502::Start() 
{
    while (m_cycles > 0)
    {
        // Get instruction from the Program Counter
        LOG(">> Program Counter\n Address: " + std::to_string(m_programCounter));
        uint8_t instruction = StepProgramCounter();
        LOG(">> Program Counter\n Instruction: " + std::to_string(instruction));
        Execute(instruction);
    }
}

void CPU6502::Execute(uint8_t instruction)
{
    switch( instruction ) {
        case CODE_LDA_IM:
            LDA_IM();
            break;
        case CODE_LDA_ZP:
            LDA_ZP();
            break;
        case CODE_LDX_IM:
            LDX_IM();
            break;
        case CODE_LDX_ZP:
            LDX_ZP();
            break;
        case CODE_JSR:
            JSR();
            break;
        default:
            break;
    }
}

void CPU6502::LDA_IM()
{
    m_accumulator = StepProgramCounter();
    m_zero = (m_accumulator == 0);
    // & is bitwise AND operator
    m_negative = (m_accumulator & 0b1000000) > 0;
    LOG(">> LDA\nvalue: " + std::to_string(m_accumulator) +"\nzero: " + std::to_string(m_zero) + "\nnegative: " + std::to_string(m_negative));
}

void CPU6502::LDA_ZP()
{
    uint8_t address = StepProgramCounter();
    m_accumulator = LoadMemory(address);
    m_zero = (m_accumulator == 0);
    m_negative = (m_accumulator & 0b1000000) > 0;
    LOG(">> LDA\nvalue: " + std::to_string(m_accumulator) +"\nzero: " + std::to_string(m_zero) + "\nnegative: " + std::to_string(m_negative));
}

void CPU6502::LDX_IM()
{
    m_registerX = StepProgramCounter();
    m_zero = (m_registerX == 0);
    m_negative = (m_registerX & 0b1000000) > 0;
    LOG(">> LDX\nvalue: " + std::to_string(m_registerX) +"\nzero: " + std::to_string(m_zero) + "\nnegative: " + std::to_string(m_negative));
}

void CPU6502::LDX_ZP()
{
    uint8_t address = StepProgramCounter();
    m_registerX = LoadMemory(address);
    m_zero = (m_registerX == 0);
    m_negative = (m_registerX & 0b1000000) > 0;
    LOG(">> LDX\nvalue: " + std::to_string(m_registerX) +"\nzero: " + std::to_string(m_zero) + "\nnegative: " + std::to_string(m_negative));
}

void CPU6502::JSR()
{
    uint16_t address = StepProgramCounter();
    uint16_t subroutine = LoadMemory(address);
    WriteMemory(m_stackPointer, (uint16_t)(m_programCounter - 1));
    m_programCounter = subroutine;
    m_cycles--;
}