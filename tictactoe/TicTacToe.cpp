#include <iostream>
#include <sstream>
#include <string>

void drawBoard(const int[9]);
void gameLoop(int[9]);
char numToChar(const int);
int gameWon(const int[9]);
bool isNumberInRange(const std::string &);
bool placeOnBoardValid(int[9], int);
void placeOnBoard(int[9], int, int);

int main()
{
    std::cout << "Welcome to this shitty TicTacToe!"
              << "\n"
              << "Instructions: \nType \"end\" to end the game\nType gameboard position to place"
              << "\n";
    int board[]{0, 0, 0, 0, 0, 0, 0, 0, 0};
    gameLoop(board);
    drawBoard(board);
    std::cout << "Thank you for playing this shitty game!" << std::endl;
    return 0;
}

void gameLoop(int board[9])
{
    std::string input;
    int position;
    bool player1Turn{true};

    int won{0};
    while (gameWon(board) == 0)
    {
        drawBoard(board);
        if (player1Turn)
        {
            std::cout << "Player1's Turn (X): ";
        }
        else
        {
            std::cout << "Player2's Turn (O): ";
        }

        std::getline(std::cin, input);

        if (input == "end")
        {
            std::cout << "\nGame Ended. No Player won.\n";
            return;
        }
        else
        {
            while (!isNumberInRange(input))
            {
                std::cout << "\nInvalid position! Type a number 0 - 8. Try again!: ";
                std::getline(std::cin, input);
            }
            std::stringstream(input) >> position;

            // place
            while (!placeOnBoardValid(board, position))
            {
                do
                {
                    std::cout << "\nTile is occupied! Type a number 0 - 8 for empty position. Try again!: ";
                    std::getline(std::cin, input);
                    std::stringstream(input) >> position;
                } while (!isNumberInRange(input));
            }
            placeOnBoard(board, position, (player1Turn ? 1 : 2));

            player1Turn = !player1Turn;
        }
    }
    if (won == 3)
    {
        std::cout << "Tie. No Player won.\n";
    }
    else
    {
        std::cout << "Congratulations! Player" << won << " " << (won == 1 ? "(X)" : "(O)") << " won!\n";
    }
}

void placeOnBoard(int board[9], int position, int number)
{
    board[position] = number;
}

bool placeOnBoardValid(int board[9], int position)
{
    if (board[position] == 0)
    {
        return true;
    }
    return false;
}

bool isNumberInRange(const std::string &str)
{
    if (str.empty())
        return false;

    for (char c : str)
    {
        if (!std::isdigit(c))
            return false;
    }

    int number;
    std::stringstream(str) >> number;

    return (number >= 0 && number <= 8);
}

// 0 = no winner, game still going
// 1 = player1 (X) is winner
// 2 = player2 (O) is winner
// 3 = Tie, Board is full
int gameWon(const int array[9])
{
    bool oneFreeSpace{false};
    for (int i = 0; i < 9; ++i)
    {
        if (array[i] == 0)
        {
            oneFreeSpace = true;
            break;
        }
    }
    if (oneFreeSpace == false)
    {
        return 3;
    }
    // horizontal
    for (int i = 0; i < 6; i = i + 3)
    {
        if (array[i] == array[i + 1] && array[i] == array[i + 2])
        {
            return array[i];
        }
    }
    // vertical
    for (int i = 0; i < 3; ++i)
    {
        if (array[i] == array[3 + i] && array[i] == array[6 + i])
        {
            return array[i];
        }
    }
    // diagonal
    if (array[0] == array[4] && array[0] == array[8])
    {
        return array[0];
    }
    if (array[2] == array[4] && array[2] == array[6])
    {
        return array[2];
    }

    return 0;
}

void drawBoard(const int array[9])
{
    for (int i = 0; i < 9; ++i)
    {
        if (i == 2 || i == 5 || i == 8)
        {
            std::cout << " " << numToChar(array[i]) << "\n";
        }
        else
        {
            std::cout << " " << numToChar(array[i]) << " |";
        }
    }
}

char numToChar(const int num)
{
    if (num == 0)
    {
        return '-';
    }
    else if (num == 1)
    {
        return 'X';
    }
    else
    {
        return 'O';
    }
}
