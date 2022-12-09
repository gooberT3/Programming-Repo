#include <iostream>
#include <fstream>

int draw(char);
int lose(char);
int win(char);

int main()
{
    int total = 0;

    std::ifstream input;
    input.open("day2_input.txt");

    if(input.is_open())
    {
        std::string line;

        while(std::getline(input, line))
        {
            char p1Move = line[0],
                 p2Move = line[2];

            if(p2Move == 'Y')
            {
                total += draw(p1Move);
            }
            else if(p2Move == 'X')
            {
                total += lose(p1Move);
            }
            else if(p2Move == 'Z')
            {
                total += win(p1Move);
            }
        }
        input.close();
    }
    else
    {
        std::cout << "Error: Could not open day2_input.txt\n";
    }

    std::cout << total;

    return 0;
}

int draw(char p1Move)
{
    int score = 0;

    if(p1Move == 'A') {score += 4;}
    else if(p1Move == 'B') {score += 5;}
    else if(p1Move == 'C') {score += 6;}

    return score;
}

int lose(char p1Move)
{
    int score = 0;

    if(p1Move == 'A') {score += 3;}
    else if(p1Move == 'B') {score += 1;}
    else if(p1Move == 'C') {score += 2;}

    return score;
}

int win(char p1Move)
{
    int score = 0;

    if(p1Move == 'A') {score += 8;}
    else if(p1Move == 'B') {score += 9;}
    else if(p1Move == 'C') {score += 7;}

    return score;
}











