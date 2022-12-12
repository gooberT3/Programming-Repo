#include <iostream>
#include <fstream>
#include <vector>
#include <map>

int calculateScore (std::string fileName) {
    std::map<char, int> player = {{'X', 1}, {'Y', 2}, {'Z', 3}};

    int score = 0;

    char opponentMove,
         playerMove;

    std::ifstream input(fileName);

    while (input >> opponentMove >> playerMove) {
        if (playerMove == 'Y') {
            if (opponentMove == 'A') { score += player[0] + player[playerMove]; } 
            else if (opponentMove == 'B') { score += player[1] + player[playerMove]; }
            else if (opponentMove == 'C') { score += player[2] + player[playerMove]; }
        }
        else if (playerMove == 'Z') {
            if (opponentMove == 'A') { score += player[1] + player[playerMove]; } 
            else if (opponentMove == 'B') { score += player[2] + player[playerMove]; }
            else if (opponentMove == 'C') { score += player[0] + player[playerMove]; }
             
        }
        std::cout << score << std::endl;
    }

    return score;
}

int main () {
    int score = calculateScore("day2_test.txt");

    std::cout << "The total score of your rock, paper, scissors game was:\n" << score;

    return 0;
}
