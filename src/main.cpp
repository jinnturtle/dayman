// DayMan is a day manager software meant to reduce decision fatigue and/or
// make managing a day easier

#include <array>
#include <chrono>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "Randomizer.hpp"
#include "version.hpp"

/* TODO this is just a quick concept test, not even a first sanity/quality pass
* has been done yet*/

enum Food_type {
    FT_Breakfast = 0,
    FT_Snack
};

struct Food_item {
    Food_item(std::string name)
    : name {name}
    , flavors {std::vector<std::string>()}
    {};
    Food_item(std::string name,
              std::vector<std::string> flavors)
    : name {name}
    , flavors {flavors}
    {};

    std::string name;
    std::vector<std::string> flavors;
    std::vector<Food_type> types;
};

int food_list_from_file(std::vector<Food_item>* arr, const std::string& fpath);

int main (/*int argc, char** argv*/) {
    std::cout << "Day Manager " << version_str() << std::endl;

    Randomizer rand;

    std::string food_general_fpath("./dat/food_general.dat");
    std::fstream ifs;
    ifs.open(food_general_fpath, std::ios_base::in);
    if (!ifs.is_open()) {
        std::cout << "ERROR: could not open " << food_general_fpath
        << " for reading" << std::endl;
        return 1;
    }

    std::vector<Food_item> general_options;
    // 0 - ready for new obj
    // 1 - got name, ready for flavors/options
    int food_read_state {0};
    while (!ifs.eof()) {
        std::string buf;
        std::getline(ifs, buf);
        //std::cout << "DEBUG: buf = " << buf << std::endl;
        if(ifs && !ifs.eof()) {
            if (buf == "") {
                food_read_state = 0;
                continue;
            } else if (buf[0] == '#') {
                // line is a comment, moving along
                continue;
            } else if (food_read_state == 0) {
                //std::cout << "DEBUG: buf (0) = " << buf << std::endl;
                general_options.push_back(Food_item(buf));
                ++food_read_state;
                continue;
            } else if (food_read_state == 1) {
                size_t pos {0};
                do {
                    //std::cout << "DEBUG: buf (1) = " << buf << std::endl;
                    pos = buf.find(",");
                    general_options.back().flavors.push_back(buf.substr(0, pos));
                    buf = buf.substr(pos+1);
                } while (pos != std::string::npos);

                food_read_state = 0;
            }
        }
    }

    //std::vector<const Food_item*> breakfast_options;
    //for (auto& opt : food_options) {
    //    for (auto& type : opt.types) {
    //        if (type == FT_Breakfast) {breakfast_options.push_back(&opt);}
    //    }
    //}

    std::time_t time =
        std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::tm* tm_time = std::gmtime(&time);

    std::cout << "Time: " << std::put_time(tm_time, "%F %T wd%u") << std::endl;

    const Food_item* opt {nullptr};
    //opt {
    //    breakfast_options[rand.roll(0, breakfast_options.size()-1)]};
    //std::cout << "Breakfast: "
    //<< opt->name
    //<< " [" << opt->flavors[rand.roll(0, opt->flavors.size()-1)] << "]"
    //<< std::endl;

    opt = &general_options[rand.roll(0, general_options.size()-1)];
    std::cout << "Lunch: "
    << opt->name
    << " [" << opt->flavors[rand.roll(0, opt->flavors.size()-1)] << "]"
    << std::endl;

    opt = &general_options[rand.roll(0, general_options.size()-1)];
    std::cout << "Dinner: "
    << opt->name
    << " [" << opt->flavors[rand.roll(0, opt->flavors.size()-1)] << "]"
    << std::endl;

    opt = &general_options[rand.roll(0, general_options.size()-1)];
    std::cout << "Supper: "
    << opt->name
    << " [" << opt->flavors[rand.roll(0, opt->flavors.size()-1)] << "]"
    << std::endl;

    return 0;
}

int food_list_from_file(std::vector<Food_item>* arr, const std::string& fpath)
{
    return 0;
}
