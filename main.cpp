#include <iostream>
#include "chip8.hpp"

int main() {
    emu::Chip8 chip = {};

    std::cout << "Chip Program Counter before updating: " << chip.PC << "\n";

    chip.PC = 0x400;

    std::cout << "Chip Program Counter after updating: " << chip.PC << "\n";

    chip.reset();

    std::cout << "Chip Program Counter after reset: " << chip.PC << "\n";

    if(chip.load_rom("roms/chip8-logo.ch8") == 0)
        std::cout << "OK!\n";

    return 0;
}
