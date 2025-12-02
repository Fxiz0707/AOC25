//
// Created by Abdullah Faiz ur rahman on 01/12/2025.
//

#ifndef DAY02_H
#define DAY02_H

#include <charconv>
#include <fstream>
#include <string>
#include <__ranges/split_view.h>
#include <__ranges/views.h>
#include <vector>
#include <iostream>
#include <set>

namespace Day02 {

    static bool is_invalid(long long id) {
        std::string as_str = std::to_string(id);
        if (as_str[0] == '0') {
            return true;
        }

        size_t l = as_str.length();
        if (l % 2 == 1) {
            return false;
        }

        std::string_view start(as_str.begin(), as_str.begin() + l / 2);
        std::string_view end(as_str.begin() + l / 2, as_str.end());

        if (start == end) {
            return true;
        }

        return false;
    }

    static long long part1() {
        std::string file_path = "puzzle_inputs/day2_input.txt";
        std::fstream input_file(file_path, std::ios::in);

        if (!input_file.is_open()) {
            throw std::runtime_error("Failed to open " + file_path);
            return 0;
        }

        std::vector<std::pair<long long, long long>> puzzle_inputs;

        std::string line;
        while (std::getline(input_file, line)) {
            auto ids = std::views::split(line, ',');
            for (const auto id_range : ids) {
                std::string_view sv(id_range.begin(), id_range.end());

                long long starting_id;
                auto [ptr1, ec1] = std::from_chars(sv.data(), sv.data() + sv.size(), starting_id);

                long long ending_id;
                auto [ptr2, ec2] = std::from_chars(ptr1 + 1, sv.data() + sv.size(), ending_id);

                puzzle_inputs.emplace_back(starting_id, ending_id);
            }
        }

        std::set<long long> invalid_ids{};
        for (auto pair : puzzle_inputs) {
            auto start = pair.first;
            auto end = pair.second;

            for (long long curr = start; curr <= end; curr ++) {
                if (is_invalid(curr)) {
                    invalid_ids.insert(curr);
                }
            }
        }

        long long total = 0;
        for (auto& invalid_id : invalid_ids) {
            total += invalid_id;
        }
        return total;
    }

    static bool is_invalid2(long long id) {
        std::string as_str = std::to_string(id);

        if (as_str[0] == '0') {
            return true;
        }

        // e.g 123123123
        for (int p = 1; p <= as_str.size() / 2; p++) {

            if (as_str.size() % p != 0) {
                continue;
            }

            auto left = as_str.begin();
            auto right = as_str.begin() + p;
            const std::string_view pattern(left, right);

            bool pattern_is_repeated = true;
            while (right <= as_str.end() - p) {
                const std::string_view next_pattern(right, right + p);

                if (pattern != next_pattern) {
                    pattern_is_repeated = false;
                    break;
                }
                left = right;
                right = right + p;
            }

            if (pattern_is_repeated) {
                return true;
            }
       }

        return false;
    }

    static long long part2() {
        std::string file_path = "puzzle_inputs/day2_input.txt";
        std::fstream input_file(file_path, std::ios::in);

        if (!input_file.is_open()) {
            throw std::runtime_error("Failed to open " + file_path);
            return 0;
        }

        std::vector<std::pair<long long, long long>> puzzle_inputs;

        std::string line;
        while (std::getline(input_file, line)) {
            auto ids = std::views::split(line, ',');
            for (const auto id_range : ids) {
                std::string_view sv(id_range.begin(), id_range.end());

                long long starting_id;
                auto [ptr1, ec1] = std::from_chars(sv.data(), sv.data() + sv.size(), starting_id);

                long long ending_id;
                auto [ptr2, ec2] = std::from_chars(ptr1 + 1, sv.data() + sv.size(), ending_id);

                puzzle_inputs.emplace_back(starting_id, ending_id);
            }
        }

        std::set<long long> invalid_ids{};
        for (auto pair : puzzle_inputs) {
            auto start = pair.first;
            auto end = pair.second;

            for (long long curr = start; curr <= end; curr ++) {
                if (is_invalid2(curr)) {
                    invalid_ids.insert(curr);
                }
            }
        }

        long long total = 0;
        for (auto& invalid_id : invalid_ids) {
            total += invalid_id;
        }
        return total;
    }

};

#endif //DAY02_H