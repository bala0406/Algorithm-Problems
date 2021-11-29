#include <iostream>
#include <vector>
#include <array>

class KnightsTourProblem
{
public:
    int BOARD_SIZE;
    std::vector<std::vector<int>> board;
    int moveCount = 0;
    std::vector<int> xMoves;
    std::vector<int> yMoves;

    KnightsTourProblem(int boardSize)
    {
        this->BOARD_SIZE = boardSize;
        this->board = std::vector<std::vector<int>>(BOARD_SIZE, std::vector<int>(BOARD_SIZE, -1));
        this->xMoves = {-2, -2, -1, -1, 1, 1, 2, 2};
        this->yMoves = {-1, 1, -2, 2, -2, 2, -1, 1};

        // initialize with first move
        this->board[0][0] = 0;
    }

    bool canKnightBePlaced(int row, int column)
    {
        // check if row or column exceeds the bounds of the chess board
        if (row < 0 || row >= BOARD_SIZE || column < 0 || column >= BOARD_SIZE)
        {
            return false;
        }

        return true;
    }

    bool solveKnightsTour(int row, int column)
    {
        // when current move count is equal to the board size, then we've found the solution
        if (moveCount == BOARD_SIZE * BOARD_SIZE - 1)
        {
            return true;
        }

        // check for all possible moves
        for (int index = 0; index < xMoves.size(); index++)
        {
            int nextMoveofRow = row + xMoves[index];
            int nextYMoveOfColumn = column + yMoves[index];

            // check if the knight can be placed in the next cell
            if (canKnightBePlaced(nextMoveofRow, nextYMoveOfColumn) && board[nextMoveofRow][nextYMoveOfColumn] == -1)
            {
                // fill the board for current move
                board[nextMoveofRow][nextYMoveOfColumn] = ++moveCount;

                // check for possible moves recursively until traversing the full chess board
                if (solveKnightsTour(nextMoveofRow, nextYMoveOfColumn))
                {
                    return true;
                }
            }
        }

        // backtrack if there's no other possible move from the current position
        board[row][column] = -1;
        moveCount--;
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

main()
{
    KnightsTourProblem *knightsTourProblem = new KnightsTourProblem(8);

    if (knightsTourProblem->solveKnightsTour(0, 0))
    {
        knightsTourProblem->printBoard();
    }
    else
    {
        std::cout << "no solution :(";
    }

    return 0;
}
