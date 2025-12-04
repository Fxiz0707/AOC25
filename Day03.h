//
// Created by Abdullah Faiz ur rahman on 02/12/2025.
//

#ifndef DAY03_H
#define DAY03_H

#include <fstream>
#include <string>
#include <vector>
#include <iostream>

namespace Day03 {

    static long long part1() {
        std::string file_path = "puzzle_inputs/day3_input.txt";
        std::fstream input_file(file_path, std::ios::in);

        if (!input_file.is_open()) {
            throw std::runtime_error("Failed to open " + file_path);
            return 0;
        }

        std::string line;

        long long total = 0;

        while (std::getline(input_file, line)) {
            int curr_max = 0;
            for (int i = 0; i < line.size(); i++) {
                for (int j = i + 1; j < line.size(); j++) {
                    int tens = (line[i] - '0');
                    int units = line[j] - '0';
                    if (tens * 10 + units> curr_max) {
                        curr_max = tens * 10 + units;
                    }
                }
            }

            total += curr_max;
        }

        return total;
    }

    static long long part2() {
        std::string file_path = "puzzle_inputs/day3_input.txt";
        std::fstream input_file(file_path, std::ios::in);

        if (!input_file.is_open()) {
            throw std::runtime_error("Failed to open " + file_path);
            return 0;
        }

        std::string line;

        long long total = 0;

        while (std::getline(input_file, line)) {
            int curr_max = 0;

            std::string largest_line = "";

            int digits = 12;
            int curr = 0;

            // 987654321111111
            // x12345678

            while (digits != 0) {
                int i = curr;
                int best_digit = line[curr] - '0';
                int best_digit_idx = curr;

                while (i + digits <= line.size()) {
                    if ((line[i] - '0') > best_digit) {
                        best_digit = line[i] - '0';
                        best_digit_idx = i;
                    }
                    i += 1;
                }

                largest_line += line[best_digit_idx];
                curr = best_digit_idx + 1;
                digits -= 1;
            }

            long long curr_total = 0;
            for (auto c : largest_line) {
                long long digit = c - '0';
                long long digit2 = std::atoi(c);


                curr_total *= 10;
                curr_total += digit;
            }
            total += curr_total;

        }


        return total;
    }

}


#endif //DAY03_H
