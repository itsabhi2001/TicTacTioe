#include <vector>

void greet();
void displayGrid(std::vector<char> inputGrid);
std::vector<char> selectPosition(std::vector<char> inputGrid, int position, int player);
std::vector<int> setScore(std::vector<int> inputScore, int position);
bool checkScore(std::vector<int> inputScore);