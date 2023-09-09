#pragma once
#include <cstdint>
// 16 bit addressing allows 65535 bytes of memory
// .. 32, 16, 8, 4, 2, 1 (Little Endian)
#define MAX_MEMORY 1024 * 64

class Memory {
    public:
        uint16_t memory[MAX_MEMORY];
    public:
        uint16_t GetSize() { return sizeof(memory); } 

        void Reset() {
            for ( int i = 0; i < GetSize(); i++)
                memory[i] = 0x0;
        }
};