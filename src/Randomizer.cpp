#include "Randomizer.hpp"

#include <cctype>
#include <cmath>
#include <cstdlib>
#include <array>
#include <list>
#include <iterator>
#include <iostream>
#include <functional>
#include <memory>
#include <sstream>
#include <tuple>

int roll_dice(unsigned n, unsigned sides,
    std::mt19937* const rng, std::stringstream& buf);

Randomizer::Randomizer()
: rng{std::mt19937(this->dev())}
{}

auto Randomizer::roll(int min, int max) -> int
{
    if(min > max) {
        int sav_min = min;
        min = max;
        max = sav_min;
    }
    std::uniform_int_distribution<std::mt19937::result_type> dist(min, max);

    return dist(this->rng);
}
