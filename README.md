# 6502-emulator
This repository contains the code for MOS 6502 emulator and simple assembler. With purpose to learn about CPUs. 6502 is a 1 Mhz 8-bit microprocessor with 64 KB ram and 56 instructions.

**Example of LDA #$FF** (with tasty bugs)

![Example program on the emulator](/media/screenshot.PNG)

## Development environment

### Building
    # Build the image
    docker build --tag 6502-environment . 
    docker run -itd -v /$(pwd):/app --name 6502-emulator 6502-environment # Start a container from the image

### Starting
    docker start 6502-emulator

## Reference
- http://6502.org/users/obelisk/6502/instructions.html
- https://www.c64-wiki.com/wiki/Reset_(Process)