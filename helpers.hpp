#ifndef _HELPERS_HPP_
#define _HELPERS_HPP_

#include <iostream>
#include <map>

#define LSB        (1 << 0)
#define BIT1        (1 << 1)
#define BIT2        (1 << 2)
#define BIT3        (1 << 3)
#define BIT4        (1 << 4)
#define BIT5        (1 << 5)
#define BIT6        (1 << 6)
#define MSB        (1 << 7)


std::string get_LSB_from_str_hex(char hex);

#endif