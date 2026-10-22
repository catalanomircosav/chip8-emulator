#include "chip8.hpp"
#include <fstream>
#include <vector>
#include <iostream>

namespace emu {
    void Chip8::reset() {
        this->registers = {};
        this->memory = {};

        this->I = 0;
        this->PC = emu::START_ADDRESS;

        this->stack = {};
        this->SP = 0;
    }

    int Chip8::load_rom(std::string filename) {
        // opening the file
        std::ifstream file(filename, std::ios::binary | std::ios::ate);

        if(file.is_open()) {
            // getting file size
            std::streampos size = file.tellg();
            if (size <= 0) {
                std::cout << "Error while reading the file!\n";
                return 1;
            }
            if (size > (std::streamoff) (memory.size() - START_ADDRESS)) {
                std::cout << "Can't read the file. ROM too big!\n";
                return 1;
            }

            // buffer allocation
            std::vector<char> buffer((std::size_t) size);

            // back to beginning of the file
            file.seekg(0, std::ios::beg);
            file.read(buffer.data(), size);
            if(file.fail()) {
                std::cout << "Error while reading the file!\n";
                return 1;
            }

            file.close();

            // loading rom
            for(std::size_t i = 0; i < buffer.size(); ++i)
                memory[START_ADDRESS + i] = buffer[i];

            return 0;
        }

        std::cout << "File not found!\n";
        return 1;
    }
}
