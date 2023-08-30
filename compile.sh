BUILD_DIR="$PWD/build"
SRC_DIR="$PWD/src"

mkdir $BUILD_DIR
cp -r $SRC_DIR/programs $BUILD_DIR/programs
g++ -std=c++11 -Wall -D DEBUG \
    -D ASSEMBLY_FILE="$($BUILD_DIR/programs/lda.asm)" \
    -o $BUILD_DIR/CPU6502 \
    -I $SRC_DIR/ \
    $SRC_DIR/main.cpp \
    $SRC_DIR/6502/cpu6502.cpp