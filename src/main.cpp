#include "cpu6502.h"

int main()
{
    auto CPU = CPU6502();
    CPU.LDA(0x0, AddressingMode::Immediate);
}