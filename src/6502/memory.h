#pragma once
#include <cstdint>
#define MAX_MEMORY 1024 * 64

class Memory {
    public:
        uint8_t memory[MAX_MEMORY];
    public:
        int32_t GetSize() { return sizeof(memory); } 

        // TODO: Does the memory reset itself or does the CPU do it?
        void Reset() {
            for ( int i = 0; i < GetSize(); i++)
                memory[i] = 0x0;
        }
};