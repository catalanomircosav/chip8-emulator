#include "chip8.hpp"

namespace emu {
    void Chip8::reset() {
        this->registers = {};
        this->memory = {};

        this->I = 0;
        this->PC = emu::START_ADDRESS;

        this->stack = {};
        this->SP = 0;
    }
}
