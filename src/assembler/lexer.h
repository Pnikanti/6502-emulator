#include <iostream>
#include <fstream>
#include <string>
#include "utils/log.h"

class Lexer {
    public:
        void ReadFile(std::string file) {
            m_file = file;
            std::string line;
            std::ifstream handle;
            handle.open(m_file);

            if (!handle.is_open()) {
                LOG("Unable to open file..");
                return;
            }

            while (std::getline(handle, line))
                LOG(line + "\n");

            handle.close();
        }
    private:
        std::string m_file;
};