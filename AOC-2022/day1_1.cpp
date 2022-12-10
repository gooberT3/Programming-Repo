#include <iostream>
#include <fstream>
#include <vector>

void fileOperations(std::ifstream&, std::vector<std::string>&);

void openFile(std::ifstream&);
void closeFile(std::ifstream&);
void readFile(std::ifstream&, std::vector<std::string>&);

int dataManipulation(std::vector<std::string>&, std::vector<int>&, int);

void storeIndividual(std::vector<std::string>&, std::vector<int>&);
int findGreatest(std::vector<int>&);

void display(int);

int main() {
    //object for reading data from the input file
    std::ifstream input;
    std::vector<std::string> fileData;

    //open the file, read and store the data into a vector of strings, close the file
    fileOperations(input, fileData);

    //container to store how much individial elf is carrying
    std::vector<int> individual;

    //manipulate the vector read from the file, calculating each elfs amount,
    //sorting the values from greatest to least, and find the greatest value
    int greatest;
    greatest = dataManipulation(fileData, individual, greatest);

    //display the greatest amount of calories to the user
    display(greatest);

    return 0;
}

//manipulating the file object to open, read, and close the file
void fileOperations(std::ifstream& input, std::vector<std::string>& fileData) {
    openFile(input);
    readFile(input, fileData);
    closeFile(input);
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

//manipulate the data read from the file
int dataManipulation(std::vector<std::string>& fileData, std::vector<int>& individial, int greatest) {
    storeIndividual(fileData, individial);
    greatest = findGreatest(individial);

    return greatest;
}

//move data from vector of strings to vector of ints for calculations
void storeIndividual(std::vector<std::string>& fileData, std::vector<int>& individual) {
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

//find the greatest amount of calories a single elf was carrying
int findGreatest(std::vector<int>& individual) {
    //variable to store the greatest amount of calories
    int greatest = 0;

    //loop to compare all elves(elements) and see which had the largest amount of calories
    for(int i = 0; i < individual.size(); i++) {
        if(individual.at(i) > greatest) {
            greatest = individual.at(i);
        }
    }

    return greatest;
}

//display the greatest amount of calories to the user
void display(int greatest) {
    std::cout << "The elf carrying the most is carrying \"" << greatest << "\" calories.";
}

