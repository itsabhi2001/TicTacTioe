#include <iostream>
#include <vector>
#include "tictactoe_functions.hpp"


int main(int argc, char *argv[]){
    bool play = true;
    while(play){
        greet();
        std::cout << "\n\n";
        std::vector<char> grid = {'1', '2', '3', '4', '5', '6' , '7', '8', '9'};
        bool win = false;
        std::vector<int> player1 = {0,0,0,0,0,0,0,0,0};
        std::vector<int> player2 = {0,0,0,0,0,0,0,0,0};
        int playSpot;
        int moves = 0;

        while (!win){
            displayGrid(grid);

            std::cout << "Player 1, select a position >>> ";
            std::cin >> playSpot;
            std::cout << "\n\n";
            grid = selectPosition(grid, playSpot, 1);
            player1 = setScore(player1, playSpot);

            displayGrid(grid);
            moves++;

            if(checkScore(player1)){
                std::cout << "Congrats Player 1. You have won.\n\n";
                break;
            }
            if(moves == 9){
                std::cout << "It is a draw.";
                break;
            }


            std::cout << "Player 2, select a position >>>";
            std::cin >> playSpot;
            std::cout << "\n\n";
            grid = selectPosition(grid, playSpot, 2);
            player2 = setScore(player2, playSpot); 

            displayGrid(grid);
            moves++;
            if(checkScore(player2)){
                std::cout << "Congrats Player 2. You have won.\n\n";
                break;
            }
            
            if(moves == 9){
                std::cout << "It is a draw.";
                break;
            }
        }
        char answer;
        std::cout << "Would you like to play again?(Y/N) >>> ";
        std::cin >> answer;
        answer = tolower(answer);
        if(answer == 'n'){
            play = false;
        }


    }
    return 0;

}