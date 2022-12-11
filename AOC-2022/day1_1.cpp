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

std::vector<int> storeIndividual(const std::vector<std::string>& fileData) {
    std::vector<int> individual;
    int currentCount = 0;

    for(auto& element : fileData) {
        if(element.empty()) {
            individual.push_back(currentCount);
            currentCount = 0;
        }
        else {
            currentCount += stoi(element);
        }
    }
    
    return individual;
}

int main() {
    std::vector<std::string> fileData = readFile("day1_input.txt");
    std::vector<int> individual = storeIndividual(fileData);

    int greatest = *std::max_element(individual.begin(), individual.end());

    std::cout << "The greatest amount amount being carried is \"" << greatest << "\" calories.\n";

    return 0;
}

