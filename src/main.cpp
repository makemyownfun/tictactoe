#include <iostream>
#include <sstream>
#include <array>
#include <string>


int main(int argc, char* arv[]) {
    bool gameOver = false;
    bool playerTurn = true;
    char val;
    int x = 0;
    int y = 0;
    int count = 0;

    int aiX = -1;
    int aiY = 0;

    using Board = std::array<std::array<char, 3>, 3>;
    Board board;
    board.fill(std::array<char, 3>{' ', ' ', ' '});

    while(!gameOver) {
        // GET NEXT MOVE FROM PLAYER OR COMPUTER
        if(playerTurn) {
            std::cout << "player's turn" << std::endl;
            val = 'x';

            // get input from the command line
            std::string input;
            getline(std::cin, input);
            std::istringstream sstream(input);
            int inputCount = 0;
            for(std::string s; sstream >> s;) {
                if(inputCount == 0) {
                    std::stringstream(s) >> x;
                    inputCount++;
                } else if(inputCount == 1) {
                    std::stringstream(s) >> y;
                    inputCount++;
                } else {
                    std::cout << "INVALID INPUT: " << s << std::endl;
                }
            }
        } 
        // it's the computers turn
        else {
            std::cout << "computer's turn" << std::endl;
            val = 'o';

            // ai selects a move
            aiX++;
            if(aiX > 2) {
                aiY++;
                aiX = -1;
            }

            x = aiX;
            y = aiY;
        }

        // ADD THE MOVE TO THE BOARD
        // if the space is already filled, continue
        if(board[x][y] != ' ') {
            std::cout << "cannot play at: " << x << " " << y << std::endl;
            continue;
        } else {
            board[x][y] = val;
        }

        // UPDATE VISUAL STATE OF THE BOARD

        // CHECK FOR A WIN CONDITION
        count++;
        if(count == 9) {
            std::cout << "scratch game" << std::endl;
            gameOver = true;
        }

        playerTurn = !playerTurn;
    }
    return 0;
}