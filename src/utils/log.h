#pragma once
#include <iostream>

#ifdef DEBUG
#define LOG(...) std::cout << (__VA_ARGS__) << std::endl
#else
#define LOG(...) 0
#endif