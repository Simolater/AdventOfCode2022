//
// Created by Simon on 04/12/2022.
//
#pragma once
#include "AoCDay.h"
#include <vector>
#include <set>
#include <unordered_map>

namespace AoC {

    using day_result_t = int64_t;

    template <>
    struct AoCDay<1> {

        using input_t = std::vector<int>;

        static input_t parseInput(std::istream& input);

        static day_result_t runA(const input_t& input);

        static day_result_t runB(const input_t& input);

    };

    template <>
    struct AoCDay<2> {

        using input_t = std::vector<std::pair<char, char>>;

        static input_t parseInput(std::istream& input);

        static day_result_t runA(const input_t& input);

        static day_result_t runB(const input_t& input);

    };

    template <>
    struct AoCDay<3> {

        using input_t = std::vector<std::string>;

        static input_t parseInput(std::istream& input);

        static day_result_t runA(const input_t& input);

        static day_result_t runB(const input_t& input);

    };

    template <>
    struct AoCDay<4> {

        using input_t = std::vector<std::array<int, 4>>;

        static input_t parseInput(std::istream& input);

        static day_result_t runA(const input_t& input);

        static day_result_t runB(const input_t& input);

    };
}