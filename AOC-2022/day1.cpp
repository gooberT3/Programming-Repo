#include <iostream>
#include <fstream>
#include <vector>
#include <string>

void getInput(std::vector<int>&);
void display(std::vector<int>&);

int main()
{
    std::vector<int> calorieCount;
    getInput(calorieCount);
    display(calorieCount);

    return 0;
}

void display(std::vector<int>& calorieCount)
{
    sort(calorieCount.begin(), calorieCount.end());
    reverse(calorieCount.begin(), calorieCount.end());
    std::cout << "The largest calorie count is:\n" << calorieCount.at(0) << std::endl;
    int total = 0;
    for(int i = 0; i < 3; i++)
    {
        total += calorieCount.at(i);
    }
    std::cout << "The top three calorie counts sum up to:\n" << total;
}

void getInput(std::vector<int>& calorieCount)
{
    std::ifstream inputData;                                     
    inputData.open("day1_input.txt");
    if(inputData.is_open())
    {
        std::string currentLine;
        int count = 0;
        while(std::getline(inputData, currentLine))
        {   
            if(currentLine.empty())
            {
                calorieCount.push_back(count);
                count = 0;
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
