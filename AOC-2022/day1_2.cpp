#include <iostream>
#include <fstream>
#include <vector>

std::vector<std::string> readFile(const std::string& fileName) {
    std::vector<std::string> fileData;

    std::string currentLine;

    std::ifstream input(fileName);

    while(getline(input, currentLine)) {
        fileData.push_back(currentLine);    
    }

    return fileData;
}

std::vector<int> findTopThree(std::vector<std::string>& fileData) { 
    std::vector<int> individual;
    int currentCount = 0;

    for(auto& i : fileData) {
        if(i.empty()) {
            individual.push_back(currentCount);
            currentCount = 0;
        }
        else {
            currentCount += stoi(i);
        }
    }

    sort(individual.begin(), individual.end(), std::greater<int>());

    std::vector<int> topThree(individual.begin(), individual.begin() + 3);

    return topThree;
}

int main() {
    std::vector<std::string> fileData = readFile("day1_input.txt");
    std::vector<int> topThree = findTopThree(fileData);

    std::cout << "The top three calorie amounts were:\n";
    for (auto& i: topThree) {
        std::cout << i << " ";
    }
    std::cout << "\n\nThe total amount is: " << topThree[0] + topThree[1] + topThree[2];

    return 0;
}
