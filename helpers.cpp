#include "helpers.hpp"

std::map<char,int> hexMap={
        {'0', 0},
        {'1', 1},
        {'2', 2},
        {'3', 3},
        {'4', 4},
        {'5', 5},
        {'6', 6},
        {'7', 7},
        {'8', 8},
        {'9', 9},
        {'A', 10},
        {'B', 11},
        {'C', 12},
        {'D', 13},
        {'E', 14},
        {'F', 15}
};


std::string get_LSB_from_str_hex(char hex){
    return std::string(1, static_cast<char>(hexMap[hex] & LSB) + '0');
}