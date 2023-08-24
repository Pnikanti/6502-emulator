# 6502-emulator
CPU emulator to learn about CPUs.

# Instructions
Reference: http://6502.org/users/obelisk/6502/instructions.html

## Development happens inside a container

    docker build --tag 6502-environment . # Build the image
    docker run -itd -v /$(pwd):/app --name 6502-emulator 6502-environment # Start a container from the image
    docker exec -iot 6502-emulator bash # Go inside the container or attach to a running container (VS code containers)