#include <iostream>
#include <fstream>
#include <vector>
#include <map>

int calculateScore(std::string fileName) {
    std::map<char, int> opponent = {{'A', 1}, {'B', 2}, {'C', 3}};
    std::map<char, int> player = {{'X', 1}, {'Y', 2}, {'Z', 3}};

    int score = 0;

    char opponentMove,
         playerMove;

    std::ifstream input(fileName);

    while(input >> opponentMove >> playerMove) {

        score += player[playerMove];
        
        if (opponent[opponentMove] == player[playerMove]) 
            score += 3; 
        else if ((opponentMove == 'A' && playerMove == 'Y') || (opponentMove == 'B' && playerMove == 'Z') || (opponentMove == 'C' && playerMove == 'X'))
            score += 6;    
    }

    return score;
}

int main() {
    int score = calculateScore("day2_input.txt");

    std::cout << "The total score of your rock, paper, scissors game was:\n" << score;

    return 0;
}
