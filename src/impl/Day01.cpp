//
// Created by Simon on 04/12/2022.
//
#include "../Days.h"
#include <sstream>

constexpr size_t c_day = 1;

AoC::AoCDay<c_day>::input_t AoC::AoCDay<c_day>::parseInput(std::istream &input) {
    input_t values;
    int sum = 0;
    for(std::string line; std::getline(input, line);) {
        if (line.empty() || line == "\r") {
            values.push_back(sum);
            sum = 0;
        } else {
            sum += std::stoi(line);
        }
    }
    values.push_back(sum);
    return values;
}

AoC::day_result_t AoC::AoCDay<c_day>::runA(const input_t &input) {
    int max = 0;
    for (auto value : input) {
        if (value > max) max = value;
    }
    return max;
}

AoC::day_result_t AoC::AoCDay<c_day>::runB(const input_t &input) {
    int a = -1, b = -1, c = -1;
    for (auto value : input) {
        if (value > c) {
            c = value;
            if (b < c) std::swap(c, b);
            if (a < b) std::swap(a, b);
        }
    }
    return a + b + c;
}