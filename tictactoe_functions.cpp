#include <iostream>
#include <vector>
#include "tictactoe_functions.hpp"


void greet(){
    std::cout << "=============\n";
     std::cout << "TicTacToe: The Game\n";
     std::cout << "=============\n";
     std::cout << "Instructions:Get Three in a Row against your opponenet. Two Player Game\n";
}

void displayGrid(std::vector<char> inputGrid){
    std::cout << " " << inputGrid[0] << " | " << inputGrid[1] << " | " << inputGrid[2] << "\n";
    std::cout << "---+---+---\n";
    std::cout << " " << inputGrid[3] << " | " << inputGrid[4] << " | " << inputGrid[5] << "\n";
    std::cout << "---+---+---\n";
    std::cout << " " << inputGrid[6] << " | " << inputGrid[7] << " | " << inputGrid[8] << "\n\n\n";
}

std::vector<char> selectPosition(std::vector<char> inputGrid, int position, int player){
    if(player == 1){
        inputGrid[position - 1] = 'X';
    }
    if(player == 2){
        inputGrid[position - 1] = 'O';
    }
    return inputGrid;
}

std::vector<int> setScore(std::vector<int> inputScore, int position){
    
    inputScore[position-1] = 1;
    return inputScore;
}

bool checkScore(std::vector<int> inputScore){
    std::vector<int> lines = {0,0,0,0,0,0,0,0};
    for(int i = 0; i <= 2; i++){
        lines[i] = inputScore[i*3] + inputScore[(i*3)+1] + inputScore[(i*3)+2];
        lines[i+3] = inputScore[i] + inputScore[i+3] + inputScore[i+6];
    }
    lines[6] = inputScore[0] + inputScore[4] + inputScore[8];
    lines[7] = inputScore[2] + inputScore[4] + inputScore[6];

    for(int i = 0; i <= 7; i++){
        if(lines[i] == 3){
            return true;
        }
    }
    return false;
}