//
// Created by Abdullah Faiz ur rahman on 04/12/2025.
//

#ifndef DAY04_H
#define DAY04_H

#include <fstream>
#include <string>
#include <vector>
#include <iostream>


namespace Day04 {

    static long long part1() {
        std::string file_path = "puzzle_inputs/day4_input.txt";
        std::fstream input_file(file_path, std::ios::in);

        if (!input_file.is_open()) {
            throw std::runtime_error("Failed to open " + file_path);
            return 0;
        }

        std::string line;
        std::vector<std::string> mat;
        while (std::getline(input_file, line)) {
            mat.push_back(line);
        }

        long long answer = 0;
        while (true) {
            std::vector<std::pair<int, int>> removed;
            long long tot = 0;
            for (int i = 0; i < mat.size(); i++) {
                for (int j = 0; j < mat[0].size(); j++) {

                    if (mat[i][j] != '@') {
                        continue;
                    }

                    int count = 0;
                    for (int x = -1; x <= 1; x++) {
                        for (int y = -1; y <= 1; y++) {
                            if (x == 0 and y == 0) {
                                continue;
                            }
                            int nx = i + x;
                            int ny = j + y;
                            if (nx < 0 or nx >= mat.size()) {
                                continue;
                            }
                            if (ny < 0 or ny >= mat[0].size()) {
                                continue;
                            }
                            if (mat[nx][ny] == '@') {
                                count += 1;
                            }
                        }
                    }

                    if (count < 4) {
                        tot += 1;
                        removed.emplace_back(i, j);
                    }
                }
            }

            for (auto pair : removed) {
                mat[pair.first][pair.second] = 'x';
            }


            answer += tot;

            std::cout << answer << std::endl;
        }

        return 0;
    }

    static long long part2() {
        std::string file_path = "puzzle_inputs/day4_input.txt";
        std::fstream input_file(file_path, std::ios::in);

        if (!input_file.is_open()) {
            throw std::runtime_error("Failed to open " + file_path);
            return 0;
        }

        std::string line;

        long long total = 0;

        while (std::getline(input_file, line)) {

        }

        return 0;
    }

}

#endif //DAY04_H
