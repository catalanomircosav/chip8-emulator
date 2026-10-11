#include <iostream>
#include <cstdint>
#include <array>

struct Chip8 {
	std::array<std::uint8_t, 4096> memory{};

	std::array<std::uint8_t, 16> V{};

	std::uint16_t I{};

	std::uint16_t PC = 0x200;
};

int main() {
	Chip8 chip{};

	std::cout << "PC: " << chip.PC << "\n";
	std::cout << "Memory[0]: " << static_cast<int>(chip.memory[0]) << "\n";
	std::cout << "V[0]: " << static_cast<int>(chip.V[0]) << "\n";

	return 0;
}