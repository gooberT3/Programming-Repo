#include <iostream>
#include <fstream>
#include <vector>
#include <string>

void getInput(std::vector<int>);
void display(std::vector<int>);

int main()
{
    std::vector<int> calorieCount;
    getInput(calorieCount);
    display(calorieCount);

    return 0;
}

void display(std::vector<int> calorieCount)
{
    for(int i = 0; i < calorieCount.size(); i++)
    {
        std::cout << calorieCount.at(i) << " ";
        std::cout << "debug";
    }
}

void getInput(std::vector<int> calorieCount)
{
    
    std::ifstream inputData;                                     
    inputData.open("day1_input.txt");
    if(inputData.is_open())
    {
        std::string currentLine;
        std::vector<int> calorieCount;
        int count = 0;
        while(std::getline(inputData, currentLine))
        {   
            if(currentLine.empty())
            {
                calorieCount.push_back(count);
            }
            else
            {
                count += stoi(currentLine);
            }
        }
    }
    else
    {
        std::cout << "Error attempting to open file...\n";
    }
}
