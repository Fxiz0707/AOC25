//
// Created by Abdullah Faiz ur rahman on 01/12/2025.
//

#ifndef DAY01_H
#define DAY01_H

#include <iostream>
#include <fstream>
#include <string>

namespace Day01 {
    static long long part1() {
        std::string file_path = "puzzle_inputs/day1_input1.txt";
        std::fstream input_file(file_path, std::ios::in);

        if (!input_file.is_open()) {
            throw std::runtime_error("Failed to open " + file_path);
            return 0;
        }

        long long count = 0;
        int current_position = 50;
        std::string line;

        while (std::getline(input_file, line)) {
            std::string numerical_part(line.begin() + 1, line.end());
            int shift = stoi(numerical_part);

            if (line[0] == 'R') {
                current_position += shift;
            }
            else {
                current_position -= shift;
            }

            current_position = (current_position % 100 + 100) % 100;

            if (current_position == 0) {
                count += 1;
            }
        }

        input_file.close();
        return count;
    }

    static long long part2() {
        std::string file_path = "puzzle_inputs/day1_input1.txt";
        std::fstream input_file(file_path, std::ios::in);

        if (!input_file.is_open()) {
            throw std::runtime_error("Failed to open " + file_path);
            return 0;
        }

        long long count = 0;
        int current_position = 50;
        std::string line;

        while (std::getline(input_file, line)) {
            std::string numerical_part(line.begin() + 1, line.end());
            int shift = stoi(numerical_part);

            count += shift / 100;
            shift = shift % 100;

            int new_position = current_position;

            if (line[0] == 'R') {
                new_position += shift;
            }
            else {
                new_position -= shift;
            }

            if (current_position == 0) {
                // nothing
            }
            else if (new_position >= 100 or new_position <= 0) {
                count += 1;
            }

            new_position = (new_position % 100 + 100) % 100;

            current_position = new_position;
        }

        input_file.close();
        return count;
    }

};



#endif //DAY01_H
