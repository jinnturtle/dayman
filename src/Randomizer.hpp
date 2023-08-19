#ifndef RANDOMIZER_HPP
#define RANDOMIZER_HPP

#include <string>
#include <random>

class Randomizer final {
public:
    Randomizer();

    int roll(int min, int max);

private:
    std::random_device dev;
    std::mt19937 rng;
};

#endif //ifndef RANDOMIZER_HPP
