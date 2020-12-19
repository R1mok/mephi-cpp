#pragma once
#include <string>
typedef unsigned int uint;

std::string to_hex(uint value);
uint F(uint X, uint Y, uint Z);
uint G(uint X, uint Y, uint Z);
uint H(uint X, uint Y, uint Z);
uint I(uint X, uint Y, uint Z);
uint rotate_left(uint value, int shift);
std::string get_md5(std::string in);