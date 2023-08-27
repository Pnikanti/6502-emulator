#include "6502/cpu6502.h"
#include "assembler/lexer.h"
#include "memory.h"

int main()
{
    auto lexer = Lexer();
    lexer.ReadFile("programs/lda.asm");
    auto mem = new Memory();
    auto CPU = CPU6502(mem, 2);

    CPU.Reset();
    // Start Inline Program

    // ASM -- Set value 30 to Accumulator
    CPU.SetMemory(0xFFFC, 0xA9); // LDA_IMMEDIATE
    CPU.SetMemory(0xFFFD, 0x30); // 0x30

    // End Inline Program
    CPU.Run();
}