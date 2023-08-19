// DayMan is a day manager software meant to reduce decision fatigue and/or
// make managing a day easier

#include <array>
#include <iostream>
#include <string>
#include <vector>

#include "Randomizer.hpp"
#include "version.hpp"

/* TODO this is just a quick concept test, not even a first sanity/quality pass
* has been done yet*/

enum Food_type {
    FT_Breakfast = 0,
    FT_Lunch,
    FT_Dinner,
    FT_Supper,
    FT_Snack
};

struct Food_item {
    Food_item(std::string name,
              std::vector<std::string> flavours,
              std::vector<Food_type> types)
    :name {name}
    ,flavours {flavours}
    ,types {types}
    {};

    std::string name;
    std::vector<std::string> flavours;
    std::vector<Food_type> types;
};

int main (/*int argc, char** argv*/) {
    std::cout << "Day Manager " << version_str() << std::endl;
    Randomizer rand;

    std::array<Food_item, 6> food_options {
        Food_item(
            "big flapjack",
            {
                "chocolate chip",
                "strawberry",
                "chocolate",
                "white chocolate",
                "can't remember",
                "plain" 
            },
            {FT_Breakfast}
        ),
        Food_item(
            "oat porridge",
            {"strawberry", "black currant", "plain"},
            {FT_Breakfast}
        ),
        Food_item(
            "fried rice",
            {
                "BBQ",
                "garalic",
                "onion",
                "soy sauce",
                "tomato & basil",
                "lemon & herb"
            },
            {FT_Lunch, FT_Dinner, FT_Supper}
        ),
        Food_item(
            "sauteed veggies",
            {"BBQ", "garalic", "soy sauce", "tomato & basil", "lemon & herb"},
            {FT_Lunch, FT_Dinner, FT_Supper}
        ),
        Food_item(
            "veggie soup",
            {"peas, corn, carrots, etc.", "cauliflower, broccoli, etc."},
            {FT_Lunch, FT_Dinner, FT_Supper}
        ),
        Food_item(
            "chocolate",
            {"dark"},
            {FT_Snack}
        )
    };

    std::vector<const Food_item*> breakfast_options;
    for (auto& opt : food_options) {
        for (auto& type : opt.types) {
            if (type == FT_Breakfast) {breakfast_options.push_back(&opt);}
        }
    }

    std::vector<const Food_item*> lunch_options;
    for (auto& opt : food_options) {
        for (auto& type : opt.types) {
            if (type == FT_Lunch) {lunch_options.push_back(&opt);}
        }
    }

    std::vector<const Food_item*> dinner_options;
    for (auto& opt : food_options) {
        for (auto& type : opt.types) {
            if (type == FT_Dinner) {dinner_options.push_back(&opt);}
        }
    }

    std::vector<const Food_item*> supper_options;
    for (auto& opt : food_options) {
        for (auto& type : opt.types) {
            if (type == FT_Supper) {supper_options.push_back(&opt);}
        }
    }

    const Food_item* opt {breakfast_options[rand.roll(0, breakfast_options.size()-1)]};
    std::cout << "Breakfast: "
    << opt->name
    << " [" << opt->flavours[rand.roll(0, opt->flavours.size()-1)] << "]"
    << std::endl;

    opt = lunch_options[rand.roll(0, lunch_options.size()-1)];
    std::cout << "Lunch: "
    << opt->name
    << " [" << opt->flavours[rand.roll(0, opt->flavours.size()-1)] << "]"
    << std::endl;

    opt = dinner_options[rand.roll(0, dinner_options.size()-1)];
    std::cout << "Dinner: "
    << opt->name
    << " [" << opt->flavours[rand.roll(0, opt->flavours.size()-1)] << "]"
    << std::endl;

    opt = supper_options[rand.roll(0, supper_options.size()-1)];
    std::cout << "Supper: "
    << opt->name
    << " [" << opt->flavours[rand.roll(0, opt->flavours.size()-1)] << "]"
    << std::endl;

    return 0;
}
