#ifndef SRC_RANDOMIZER_HPP_
#define SRC_RANDOMIZER_HPP_

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
