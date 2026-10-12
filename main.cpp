
#include <iostream>
#include <array>
#include <cstdint>
#include <cstddef>
#include <cassert>

constexpr std::size_t RAM_SIZE = 4096;
constexpr std::size_t STACK_SIZE = 16;
constexpr std::size_t NUM_REGS = 16;

struct Chip8
{
    std::uint16_t pc = 0x200;

    std::array<std::uint8_t, RAM_SIZE> ram{};
    std::array<std::uint8_t, NUM_REGS> regs{};

    std::uint16_t i_reg = 0;

    std::array<std::uint16_t, STACK_SIZE> stack{};
    std::uint8_t sp = 0;

    std::uint8_t dt = 0;
    std::uint8_t st = 0;

    void push(std::uint16_t val)
    {
        assert(sp < stack.size() && "Stack overflow");

        stack[sp] = val;
        ++sp;
    }

    std::uint16_t pop()
    {
        assert(sp > 0 && "Stack underflow");

        --sp;
        return stack[sp];
    }
};

int main()
{
    Chip8 chip{};

    assert(chip.pc == 0x200);
    assert(chip.sp == 0);
    assert(chip.i_reg == 0);

    chip.push(0x250);
    chip.push(0x380);

    std::cout << "SP dopo due push: "
              << static_cast<int>(chip.sp) << '\n';

    std::cout << "Primo pop: 0x"
              << std::hex << chip.pop() << '\n';

    std::cout << "Secondo pop: 0x"
              << std::hex << chip.pop() << '\n';

    std::cout << "SP finale: "
              << std::dec << static_cast<int>(chip.sp) << '\n';

    assert(chip.sp == 0);

    return 0;
}
