//
// Created by Simon on 04/12/2022.
//
#include "../Days.h"
#include <sstream>

constexpr size_t c_day = 4;

AoC::AoCDay<c_day>::input_t AoC::AoCDay<c_day>::parseInput(std::istream &input) {
    input_t values;
    for (std::string line; std::getline(input, line);) {
        std::array<int, 4> numbers{};
        numbers[0] = std::stoi(line.substr(0, line.find('-')));
        numbers[1] = std::stoi(line.substr(line.find('-') + 1, line.find(',')));
        auto second_half = line.substr(line.find(',') + 1, line.length());
        numbers[2] = std::stoi(second_half.substr(0, second_half.find('-')));
        numbers[3] = std::stoi(second_half.substr(second_half.find('-') + 1, second_half.length()));
        values.emplace_back(numbers);
    }
    return values;
}

AoC::day_result_t AoC::AoCDay<c_day>::runA(const input_t &input) {
    int score = 0;
    for (const auto& values : input) {
        if ((values[0] >= values[2] && values[1] <= values[3]) || (values[0] <= values[2] && values[1] >= values[3])) ++score;
    }
    return score;
}

AoC::day_result_t AoC::AoCDay<c_day>::runB(const input_t &input) {
    int score = 0;
    for (const auto& values : input) {
        if (values[1] >= values[2] && values[0] <= values[3]) ++score;
    }
    return score;
}