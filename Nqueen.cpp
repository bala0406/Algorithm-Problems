#include <iostream>
#include <vector>
#include <unordered_map>

class NQueen
{
public:
    int BOARD_SIZE;
    std::vector<std::vector<int>> board;
    std::unordered_map<int, int> solutionSet;
    NQueen(int boardSize)
    {
        this->BOARD_SIZE = boardSize;
        this->board = std::vector<std::vector<int>>(BOARD_SIZE, std::vector<int>(BOARD_SIZE, 0));
    }

    bool canQueenBePlaced(int row, int column)
    {
        for (std::unordered_map<int, int>::iterator index = solutionSet.begin(); index != solutionSet.end(); index++)
        {
            // check top left and top right diagonal (absolute difference between the columns and rows are equal if the queens are in the diagonal)
            if (std::abs(row - index->first) == std::abs(column - index->second))
            {
                return false;
            }

            // check vertically
            if (index->second == column)
            {
                return false;
            }
        }

        return true;
    }

    bool solveNQueen(int row, int column)
    {
        // if solution set is greater than or equal to board size then all queens have been placed
        if (solutionSet.size() >= BOARD_SIZE)
        {
            return true;
        }

        // check all cells in each row for the queen to be placed
        for (int columnIndex = 0; columnIndex < this->BOARD_SIZE; columnIndex++)
        {
            if (canQueenBePlaced(row, columnIndex) && this->board[row][columnIndex] == 0)
            {
                this->board[row][columnIndex] = 1;
                solutionSet.insert(std::make_pair(row, columnIndex));

                // recursively solve for next queen placement
                if (solveNQueen(row + 1, columnIndex))
                {
                    return true;
                }
            }
            // if the queen cannot be placed in the current cell, set the value to zero and delete the coresponding solution
            this->board[row][columnIndex] = 0;
            solutionSet.erase(row);
        }

        // backtrack if the queen cannot be placed in any cell of the row
        row--;
        return false;
    }

    void printBoard()
    {
        for (std::vector<int> element : this->board)
        {
            for (int path : element)
            {
                std::cout << path << "\t";
            }
            std::cout << "\n";
        }
    }
};

int main()
{
    NQueen *nQueen = new NQueen(8);

    if (nQueen->solveNQueen(0, 0))
    {
        nQueen->printBoard();
    }
    else
    {
        std::cout << "no solution :(";
    }
}
