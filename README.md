# 6502-emulator
This repository contains the code for MOS 6502 emulator. With the purpose to learn about CPUs. 6502 is a 1 Mhz 8-bit microprocessor with 64 KB ram and 56 instructions.

The repository also contains the code for a simple 6502 assembler.

## Reference
http://6502.org/users/obelisk/6502/instructions.html

## Development environment

### First time
    # Build the image
    docker build --tag 6502-environment . 
    docker run -itd -v /$(pwd):/app --name 6502-emulator 6502-environment # Start a container from the image
    # To go inside the container or attach to a running container (VS code containers)
    docker exec -iot 6502-emulator bash 

### 
    docker start 6502-emulator