#include <bits/stdc++.h>
using namespace std;

void PrintBoard(char board[3][3])
{
    cout << "PLAYER - 1 [X]   PLAYER - 2 [O]";
    cout << endl
         << endl;
    cout << "     |     |     ";
    cout << endl;
    cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << " ";
    cout << endl;
    cout << "_____|_____|_____";
    cout << endl;
    cout << "     |     |     ";
    cout << endl;
    cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << " ";
    cout << endl;
    cout << "_____|_____|_____";
    cout << endl;
    cout << "     |     |    ";
    cout << endl;
    cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << " ";
    cout << endl;
    cout << "     |     |     ";
    cout << endl
         << endl;
}

bool Result(char board[3][3], bool &draw)
{
    for (int i = 0; i < 3; i++)
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])
            return false;

    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0])
        return false;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return true;

    draw = true;
    return false;
}

void Move(char board[3][3], char &turn, int row, int col, int choice)
{
    if (turn == 'X')
    {
        cout << "Player - 1 [X] turn : ";
    }
    else if (turn == 'O')
    {
        cout << "Player - 2 [O] turn : ";
    }

    cin >> choice;
    cout << endl;

    switch (choice)
    {
    case 1:
        row = 0;
        col = 0;
        break;
    case 2:
        row = 0;
        col = 1;
        break;
    case 3:
        row = 0;
        col = 2;
        break;
    case 4:
        row = 1;
        col = 0;
        break;
    case 5:
        row = 1;
        col = 1;
        break;
    case 6:
        row = 1;
        col = 2;
        break;
    case 7:
        row = 2;
        col = 0;
        break;
    case 8:
        row = 2;
        col = 1;
        break;
    case 9:
        row = 2;
        col = 2;
        break;
    default:
        cout << "Invalid Move" << endl;
        cout << endl;
    }

    if (turn == 'X' && board[row][col] != 'X' && board[row][col] != 'O')
    {
        board[row][col] = 'X';
        turn = 'O';
    }
    else if (turn == 'O' && board[row][col] != 'X' && board[row][col] != 'O')
    {

        board[row][col] = 'O';
        turn = 'X';
    }
    else
    {
        cout << "Box already filled!" << endl
             << "Please choose another!!" << endl;
        Move(board, turn, row, col, choice);
    }
}

void Game()
{
    char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    int choice;
    int row, col;
    char turn = 'X';
    bool draw = false;

    cout << endl;
    cout << "             TIC ---- TAC ---- TOE ---- GAME                ";
    cout << endl;
    cout << "                 TWO PLAYER GAME MODE                        ";
    cout << endl;
    while (Result(board, draw))
    {
        PrintBoard(board);
        Move(board, turn, row, col, choice);
        Result(board, draw);
    }
    PrintBoard(board);
    if (turn == 'O' && draw == false)
    {
        cout << "Congratulations! Player with 'X' has won the game." << endl;
        cout << endl;
    }
    else if (turn == 'X' && draw == false)
    {
        cout << "Congratulations! Player with 'O' has won the game." << endl;
        cout << endl;
    }
    else
    {
        cout << "GAME DRAW!!!  " << endl;
        cout << endl;
    }
}
int main()
{
    Game();
    char response;
    cout << "ENTER 'Y' TO PLAY AGAIN OR ENTER 'N' TO EXIT" << endl;
    cin >> response;
    while (response != 'Y' && response != 'N')
    {
        cout << "INVALID RESPONSE!!" << endl;
        cout << "ENTER A VALID RESPONSE : ";
        cin >> response;
        cout << endl;
    }
    while (response == 'Y')
    {
        Game();
        cout << "ENTER 'Y' TO PLAY AGAIN OR ENTER 'N' TO EXIT" << endl;
        cin >> response;
        while (response != 'Y' && response != 'N')
        {
            cout << "INVALID RESPONSE!!" << endl;
            cout << "ENTER A VALID RESPONSE : ";
            cin >> response;
            cout << endl;
        }
    }
    if (response == 'N')
        cout << "THANK YOU FOR PLAYING!! " << endl;
    return 0;
}