BUILD_DIR="$PWD/build"
SRC_DIR="$PWD/src"
CPP_VERSION="c++11"

mkdir $BUILD_DIR
cp -r $SRC_DIR/programs $BUILD_DIR/programs
g++ -std=$CPP_VERSION \
    -g3 \
    -O0 \
    -Wall \
    -D DEBUG \
    -D ASSEMBLY_FILE="$($BUILD_DIR/programs/lda.asm)" \
    -o $BUILD_DIR/CPU6502 \
    -I $SRC_DIR/ \
    $SRC_DIR/main.cpp \
    $SRC_DIR/6502/cpu6502.cpp