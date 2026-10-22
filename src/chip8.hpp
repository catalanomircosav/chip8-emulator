#pragma once
#include <cstdint>
#include <array>
#include <string>
#include <optional>

namespace emu {
    const uint16_t START_ADDRESS = 0x200;

    class Chip8 {

        public:
            // 16 registers
            std::array<uint8_t, 16> registers = {};

            // 4096 bytes of memory
            std::array<uint8_t, 4096> memory = {};

            uint16_t I = 0;
            uint16_t PC = START_ADDRESS;            // in the chip8 the program counter starts on 0x200 and not on 0

            std::array<uint16_t, 16> stack = {};
            uint8_t SP = {};

        public:
            void reset();
            int load_rom(std::string filename);
            std::optional<uint16_t> fetch();
    };
}
