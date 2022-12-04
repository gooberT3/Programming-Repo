#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() {
    std::string calories;
    int temp = 0;

    std::vector<int> per_elf;

    std::ifstream input_data;
    input_data.open("day1_input.txt");

    if(input_data.is_open()) {
        while(std::getline(input_data, calories)) {
            if(calories.empty()) {
                per_elf.push_back(temp);
                temp = 0;
            } else {
                temp += stoi(calories);
            }
        }     
    } else {
        std::cout << "Error on file open...\n";
    }

    for(int i = 0; i < per_elf.size(); i++) {
        for(int j = 0; j < per_elf.size() - 1; j++) {
            if(per_elf.at(j) > per_elf.at(j + 1)) {
                int temp = per_elf.at(j);
                per_elf.at(j) = per_elf.at(j + 1);
                per_elf.at(j + 1) = temp;
            }
        }
    }
    for(int i = 0; i < per_elf.size(); i++) {
        std::cout << per_elf.at(i) << std::endl;
    }

    return 0;
}
