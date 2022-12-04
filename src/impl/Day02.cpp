//
// Created by Simon on 04/12/2022.
//
#include "../Days.h"
#include <sstream>

constexpr size_t c_day = 2;

AoC::AoCDay<c_day>::input_t AoC::AoCDay<c_day>::parseInput(std::istream &input) {
    input_t values;
    for (std::string line; std::getline(input, line);) {
        values.emplace_back(line[0], line[2]);
    }
    return values;
}

AoC::day_result_t AoC::AoCDay<c_day>::runA(const input_t &input) {
    int score = 0;
    for (auto& [opp, me] : input) {
        score += (me - 'X') + 1;

        int diff = (opp - 'A') - (me - 'X');
        score += ((3 - (diff + 5) % 3) % 3) * 3;
    }
    return score;
}

AoC::day_result_t AoC::AoCDay<c_day>::runB(const input_t &input) {
    int score = 0;
    for (auto [opp, me] : input) {
        score += (me - 'X') * 3;
        score += ((opp - 'A') + (me - 'Y') + 3) % 3 + 1;
    }
    return score;
}