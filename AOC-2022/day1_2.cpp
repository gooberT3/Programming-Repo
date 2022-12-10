#include <iostream>
#include <fstream>
#include <vector>

void openFile(std::ifstream&);
void closeFile(std::ifstream&);
void readFile(std::ifstream&, std::vector<std::string>&);
void convertVecs(std::vector<std::string>&, std::vector<int>&);
void sortVec(std::vector<int>&, std::vector<int>&);
void display(std::vector<int>&);

int main() {
    //object for reading data from the input file
    std::ifstream input;
    std::vector<std::string> fileData;

    //open the file, read and store the data into a vector of strings, close the file
    openFile(input);
    readFile(input, fileData);
    closeFile(input);

    //container to store how much individial elf is carrying
    std::vector<int> individual;
    convertVecs(fileData, individual);

    //container to hold top three highest calories amounts
    std::vector<int> topThree;

    //sorts vec of ints from greatest to least
    sortVec(individual, topThree);

    //display the three largest calorie amounts
    display(topThree);

    return 0;
}

//open the input file
void openFile(std::ifstream& input) {
    input.open("day1_input.txt");
}

//close the input file
void closeFile(std::ifstream& input) {
    input.close();
}

//read data from the input file into a vector of strings
void readFile(std::ifstream& input, std::vector<std::string>& fileData) {
    std::string tempStorage;

    while(getline(input, tempStorage)) {
        fileData.push_back(tempStorage);    
    }
}

//converts the data from strings to ints
void convertVecs(std::vector<std::string>& fileData, std::vector<int>& individual) {
    //variable to keep count of the current elfs calories
    int currentCount = 0;

    //loop to move through and transfer data between vectors
    for(int i = 0; i < fileData.size(); i++) {
        if(fileData.at(i).empty()) {
            individual.push_back(currentCount);
            currentCount = 0;
        }
        else {
            currentCount += stoi(fileData.at(i));
        }
    }
}

//sorts the vec of ints from greatest to least
void sortVec(std::vector<int>& individual, std::vector<int>& topThree) {
    //loop to determine which vec element to start the new sort pass from
    for(int i = 0; i < individual.size(); i++) {
        //loop to move through and sort the vec starting from the position defined in the first loop
        for(int j = 0; j < individual.size() - 1; j++) {
            //if the element after the current one is larger, swap the places
            if(individual.at(j) < individual.at(j + 1)) {
                std::swap(individual.at(j), individual.at(j + 1));
            }
        }
    }

    //store the top three amounts
    for(int i = 0; i < 3; i++) {
        topThree.push_back(individual.at(i));
    }
}

//display the greatest amount of calories to the user
void display(std::vector<int>& topThree) {
    std::cout << "The three largest calorie amounts were:\n";

    //display top three amounts
    for(int i = 0; i < topThree.size(); i++) {
        std::cout << i + 1 << " -> " << topThree.at(i) << std::endl;
    }

    //display total amount of top three
    std::cout << "\nThe total amount of calories between the three is:\n"
              << topThree.at(0) + topThree.at(1) + topThree.at(2);
}















