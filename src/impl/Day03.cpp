//
// Created by Simon on 04/12/2022.
//
#include "../Days.h"
#include <sstream>

constexpr size_t c_day = 3;

AoC::AoCDay<c_day>::input_t AoC::AoCDay<c_day>::parseInput(std::istream &input) {
    input_t values;
    for (std::string line; std::getline(input, line);) {
        values.emplace_back(std::move(line));
    }
    return values;
}

AoC::day_result_t AoC::AoCDay<c_day>::runA(const input_t &input) {
    int score = 0;
    for (const auto& line : input) {
        std::set<char> chars;
        for (auto i = 0; i < line.length() / 2; ++i) {
            chars.insert(line[i]);
        }
        for (auto i = line.length() / 2; i < line.length(); ++i) {
            const auto c = line[i];
            if (chars.contains(c)) {
                if (std::islower(c)) {
                    score += c - 'a' + 1;
                } else {
                    score += c - 'A' + 27;
                }
                break;
            }
        }
    }
    return score;
}

AoC::day_result_t AoC::AoCDay<c_day>::runB(const input_t &input) {
    int score = 0;
    for (auto i = 0; i < input.size(); i += 3) {
        std::set<char> first{input[i].begin(), input[i].end()};
        std::set<char> second{input[i + 1].begin(), input[i + 1].end()};
        std::vector<char> shared;
        std::set_intersection(first.begin(), first.end(), second.begin(), second.end(), std::back_inserter(shared));
        std::set<char> shared_set{shared.begin(), shared.end()};
        for (char c : input[i + 2]) {
            if (shared_set.contains(c)) {
                if (std::islower(c)) {
                    score += c - 'a' + 1;
                } else {
                    score += c - 'A' + 27;
                }
                break;
            }
        }
    }
    return score;
}