// project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ios>
#include <iomanip>
#include <stdlib.h>
#include <Windows.h>
#include <climits>
#define STD_OUTPUT_HANDLE ((DWORD)-11)
using namespace std;

void setColor(int c)
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console, c);
}

void boardDisplay(int board[][6], int& southStore, int& northStore)
{
    cout << endl;
    setColor(9); cout << "\t\t f \t\t\ e \t\t d \t\t c \t\t b \t\t a \t\n";
    setColor(15); 
    cout << "\t=================================================================================================\n"
        << "\t|\t\t|\t\t|\t\t|\t\t|\t\t|\t\t|\n"
        << "\t|\t";
    setColor(9); cout << board[0][0]; 
    setColor(15); cout << "\t|\t"; 
    setColor(9); cout << board[0][1]; 
    setColor(15); cout << "\t|\t"; 
    setColor(9); cout << board[0][2];
    setColor(15); cout << "\t|\t";
    setColor(9); cout << board[0][3];
    setColor(15); cout << "\t|\t";
    setColor(9); cout << board[0][4];
    setColor(15); cout << "\t|\t";
    setColor(9); cout << board[0][5];
    setColor(15); cout << "\t|     ";
    setColor(9); cout << "North Store : " << northStore << endl;
    setColor(15); 
    cout << "\t|\t\t|\t\t|\t\t|\t\t|\t\t|\t\t|\n"
        << "\t=================================================================================================\n"
        << "\t|\t\t|\t\t|\t\t|\t\t|\t\t|\t\t|\n"
        << "\t|\t";
    setColor(4); cout << board[1][0];
    setColor(15); cout << "\t|\t";
    setColor(4); cout << board[1][1];
    setColor(15); cout << "\t|\t";
    setColor(4); cout << board[1][2];
    setColor(15); cout << "\t|\t";
    setColor(4); cout << board[1][3];
    setColor(15); cout << "\t|\t";
    setColor(4); cout << board[1][4];
    setColor(15); cout << "\t|\t";
    setColor(4); cout << board[1][5];
    setColor(15); cout << "\t|     ";
    setColor(4); cout << "South Store : " << southStore << endl;
    setColor(15);
    cout << "\t|\t\t|\t\t|\t\t|\t\t|\t\t|\t\t|\n"
        << "\t=================================================================================================\n";
    setColor(4); cout << "\t\t A \t\t\ B \t\t C \t\t D \t\t E \t\t F \t\n\n";

    setColor(15);
}

bool validHoleInput(char& hole, int& currentPlayer)
{ 
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(1000000000000000000, '\n');
        return false;
    }

    if (currentPlayer == 1)
    {
        if (hole != 'A' && hole != 'B' && hole != 'C' && hole != 'D' && hole != 'E' && hole != 'F')
            return false;
    }
    else
    {
        if (hole != 'a' && hole != 'b' && hole != 'c' && hole != 'd' && hole != 'e' && hole != 'f')
            return false;
    }

    return true;
}

bool emptyHole(char& hole, int board[][6])
{
    switch (hole)
    {
    case 'A': if (board[1][0] == 0) return true; else return false;
    case 'B': if (board[1][1] == 0) return true; else return false;
    case 'C': if (board[1][2] == 0) return true; else return false;
    case 'D': if (board[1][3] == 0) return true; else return false;
    case 'E': if (board[1][4] == 0) return true; else return false;
    case 'F': if (board[1][5] == 0) return true; else return false;

    case 'a': if (board[0][5] == 0) return true; else return false;
    case 'b': if (board[0][4] == 0) return true; else return false;
    case 'c': if (board[0][3] == 0) return true; else return false;
    case 'd': if (board[0][2] == 0) return true; else return false;
    case 'e': if (board[0][1] == 0) return true; else return false;
    case 'f': if (board[0][0] == 0) return true; else return false;
    }
}

void collect(int& currentPlayer, int& chosenHole, int& currentSouthIndex, int& currentNorthIndex, int board[][6], int& southHand, int& northHand)
{
    char hole;
    bool oneChar = true; 

    cout << "\tChoose one of the holes on your own side of the board and collect all the seeds on it.\n";

    // when choosing a hole, if the player introduces more than one character, oneChar = false
    // HOWEVER, if a player happens to introduce a valid letter plus some random characters, the valid letter will count as his move and the rest will be ignored

    do
    {
        switch (currentPlayer)
        {
        case 1:
            cout << "\tA|B|C|D|E|F: "; cin >> hole; 
            break;
        case -1:
            cout << "\tf|e|d|c|b|a: "; cin >> hole; 
            break;
        }

        cin.ignore(1000000000000000000, '\n'); 

        if (validHoleInput(hole, currentPlayer) == false)
            cout << "\tThat hole is not valid. Please make sure you type a valid hole.\n";
        else if (emptyHole(hole, board))
            cout << "\tThat hole is empty. Please choose another one.\n";

    } while (validHoleInput(hole, currentPlayer) == false || emptyHole(hole, board) || !oneChar);

    switch (hole)
    {
    // uppercase letters correspond to the south player
    case 'A':
        southHand = board[1][0];
        currentSouthIndex = 0;
        chosenHole = 0;
        board[1][0] = 0;
        break;
    case 'B':
        southHand = board[1][1];
        currentSouthIndex = 1;
        chosenHole = 1;
        board[1][1] = 0;
        break;
    case 'C':
        southHand = board[1][2];
        currentSouthIndex = 2;
        chosenHole = 2;
        board[1][2] = 0;
        break;
    case 'D':
        southHand = board[1][3];
        currentSouthIndex = 3;
        chosenHole = 3;
        board[1][3] = 0;
        break;
    case 'E':
        southHand = board[1][4];
        currentSouthIndex = 4;
        chosenHole = 4;
        board[1][4] = 0;
        break;
    case 'F':
        southHand = board[1][5];
        currentSouthIndex = 5;
        chosenHole = 5;
        board[1][5] = 0;
        break;

    // lowercase letters correspond to the south player
    case 'f':
        northHand = board[0][0];
        currentNorthIndex = 11;
        chosenHole = 11;
        board[0][0] = 0;
        break;
    case 'e':
        northHand = board[0][1];
        currentNorthIndex = 10;
        chosenHole = 10;
        board[0][1] = 0;
        break;
    case 'd':
        northHand = board[0][2];
        currentNorthIndex = 9;
        chosenHole = 9;
        board[0][2] = 0;
        break;
    case 'c':
        northHand = board[0][3];
        currentNorthIndex = 8;
        chosenHole = 8;
        board[0][3] = 0;
        break;
    case 'b':
        northHand = board[0][4];
        currentNorthIndex = 7;
        chosenHole = 7;
        board[0][4] = 0;
        break;
    case 'a':
        northHand = board[0][5];
        currentNorthIndex = 6;
        chosenHole = 6;
        board[0][5] = 0;
        break;
    }
}

void sow(int& currentPlayer, int& chosenHole, int& currentSouthIndex, int& currentNorthIndex, int board[][6], int& southHand, int& northHand)
{
    // mod 12 is applied to prevent cases where the player has twelve or more seeds on his hand to sow and so goes round around the board on that phase
    
    switch (currentPlayer)
    {
    case 1:
        while (southHand != 0)
        {
            currentSouthIndex = (currentSouthIndex + 1) % 12;
            if (currentSouthIndex != chosenHole)
            {
                switch (currentSouthIndex)
                {
                case 0: board[1][0] += 1; break;
                case 1: board[1][1] += 1; break;
                case 2: board[1][2] += 1; break;
                case 3: board[1][3] += 1; break;
                case 4: board[1][4] += 1; break;
                case 5: board[1][5] += 1; break;
                case 6: board[0][5] += 1; break;
                case 7: board[0][4] += 1; break;
                case 8: board[0][3] += 1; break;
                case 9: board[0][2] += 1; break;
                case 10: board[0][1] += 1; break;
                case 11: board[0][0] += 1; break;
                }
                southHand -= 1;
            }
            else
                continue;
        }
        break;

    case -1:
        while (northHand != 0)
        {
            currentNorthIndex = (currentNorthIndex + 1) % 12;
            if (currentNorthIndex != chosenHole)
            {
                switch (currentNorthIndex)
                {
                case 0: board[1][0] += 1; break;
                case 1: board[1][1] += 1; break;
                case 2: board[1][2] += 1; break;
                case 3: board[1][3] += 1; break;
                case 4: board[1][4] += 1; break;
                case 5: board[1][5] += 1; break;
                case 6: board[0][5] += 1; break;
                case 7: board[0][4] += 1; break;
                case 8: board[0][3] += 1; break;
                case 9: board[0][2] += 1; break;
                case 10: board[0][1] += 1; break;
                case 11: board[0][0] += 1; break;
                }
                northHand -= 1;
            }
            else
                continue;  
        }
        break;
    }
}

bool validCaptureMove(int& currentPlayer, int& currentSouthIndex, int& currentNorthIndex, int board[][6])
{
    // a player can never capture all the seeds of the adversary
    // a move that would capture all the seeds on the opponent's side is not considered legal
  
    int ix; 

    switch (currentPlayer)
    {
    case 1:
        switch (currentSouthIndex)
        {
        case 11: ix = 0; break;
        case 10: ix = 1; break;
        case 9: ix = 2; break;
        case 8: ix = 3; break;
        case 7: ix = 4; break;
        case 6: ix = 5; break;
        }

        for (int i = ix; i < 6; i++)
        {
            if (board[0][ix] != 0 || (board[0][ix] != 2 && board[0][ix] != 3))
                return true;
        }
        break;

    case -1:
        ix = currentNorthIndex;
        for (int i = ix; i < 6; i++)
        {
            if (board[1][ix] != 0 || (board[1][ix] != 2 && board[1][ix] != 3))
                return true;
        }
        break;
    }
    return false;
}

void capture(int& currentPlayer, int& currentSouthIndex, int& currentNorthIndex, int& southStore, int& northStore, int board[][6])
{
    // since it is a void function, it won't return any value
    // however, when certain conditions are met, such as, when the player is on his side of the board at the begining of the capture phase, and seeds to capture would be his own, 
    // the function returns, since it is not considered a legal move

    if (currentPlayer == 1 && (currentSouthIndex == 0 || currentSouthIndex == 1 || currentSouthIndex == 2 || currentSouthIndex == 3 || currentSouthIndex == 4 || currentNorthIndex == 5))
    {
        cout << "\tThere was no capture phase because you can't capture seeds from your own side of the board.\n\n"; return;
    }
        
    if (currentPlayer == -1 && (currentNorthIndex == 6 || currentNorthIndex == 7 || currentNorthIndex == 8 || currentNorthIndex == 9 || currentNorthIndex == 10 || currentNorthIndex == 11))
    {
        cout << "\tThere was no capture phase because you can't capture seeds from your own side of the board.\n\n"; return;
    }

    int ix;
    if (currentPlayer == 1)
        ix = currentSouthIndex;
    else
        ix = currentNorthIndex;

    if (validCaptureMove(currentPlayer, currentSouthIndex, currentNorthIndex, board))
    {
        switch (currentPlayer)
        {
        case 1:
            for (int i = ix; i >= 6; i--)
            {
                switch (i)
                {
                case 6:
                    if (board[0][5] == 2 || board[0][5] == 3)
                    {
                        southStore += board[0][5];
                        board[0][5] = 0;
                        currentSouthIndex -= 1;
                    }
                    else return;
                    break;
                case 7:
                    if (board[0][4] == 2 || board[0][4] == 3)
                    {
                        southStore += board[0][4];
                        board[0][4] = 0;
                        currentSouthIndex -= 1;
                    }
                    else return;
                    break;
                case 8:
                    if (board[0][4] == 2 || board[0][4] == 3)
                    {
                        southStore += board[0][3];
                        board[0][3] = 0;
                        currentSouthIndex -= 1;
                    }
                    else return;
                    break;
                case 9:
                    if (board[0][2] == 2 || board[0][2] == 3)
                    {
                        southStore += board[0][2];
                        board[0][2] = 0;
                        currentSouthIndex -= 1;
                    }
                    else return;
                    break;
                case 10:
                    if (board[0][1] == 2 || board[0][1] == 3)
                    {
                        southStore += board[0][1];
                        board[0][1] = 0;
                        currentSouthIndex -= 1;
                    }
                    else return;
                    break;
                case 11:
                    if (board[0][0] == 2 || board[0][0] == 3)
                    {
                        southStore += board[0][0];
                        board[0][0] = 0;
                        currentSouthIndex -= 1;
                    }
                    else return;
                    break;
                }
            }
            break;
        case -1:
            for (int i = ix; i >= 0; i--)
            {
                switch (i)
                {
                case 0:
                    if (board[1][0] == 2 || board[1][0] == 3)
                    {
                        northStore += board[1][0];
                        board[1][0] = 0;
                        currentNorthIndex -= 1;
                    }
                    else return;
                    break;
                case 1:
                    if (board[1][1] == 2 || board[1][1] == 3)
                    {
                        northStore += board[1][1];
                        board[1][1] = 0;
                        currentNorthIndex -= 1;
                    }
                    else return;
                    break;
                case 2:
                    if (board[1][2] == 2 || board[1][2] == 3)
                    {
                        northStore += board[1][2];
                        board[1][2] = 0;
                        currentNorthIndex -= 1;
                    }
                    else return;
                    break;
                case 3:
                    if (board[1][3] == 2 || board[1][3] == 3)
                    {
                        northStore += board[1][3];
                        board[1][3] = 0;
                        currentNorthIndex -= 1;
                    }
                    else return;
                    break;
                case 4:
                    if (board[1][4] == 2 || board[1][4] == 3)
                    {
                        northStore += board[1][4];
                        board[1][4] = 0;
                        currentNorthIndex -= 1;
                    }
                    else return;
                    break;
                case 5:
                    if (board[1][5] == 2 || board[1][5] == 3)
                    {
                        northStore += board[1][5];
                        board[1][5] = 0;
                        currentNorthIndex -= 1;
                    }
                    else return;
                    break;
                }
            }
            break;
        }
    }
    else
        cout << "\tSorry, you are not allowed to make that move since it would capture all the seeds on the opponent's side.\n"
        << "\tTry again next round.\n\n";
}

void gameRules()
{
    cout << endl << endl;
    setColor(9);
    cout << "\t1) EQUIPMENT AND INITIAL SETUP\n\n"; 
    setColor(15);
    cout << "\t- to play oware you will need a game board and forty-eight game pieces, which are so-called seeds\n"
        << "\t- the board consists of two rows of six holes located at opposite sides\n"
        << "\t- the bottom row belongs to the player who moves first, named south, and the upper row to the second player or north\n"
        << "\t- two larger holes on the sides of the board are used to store the seeds players capture during the match\n\n";
    setColor(9);
    cout << "\t2) GOAL OF THE GAME\n\n"; 
    setColor(15);
    cout << "\t- the goal of oware is to capture the greatest amount of seeds as possible\n"
        << "\t- players make moves in alternate turns until one of them has captured more than 24 seeds\n"
        << "\t- the player who captured more seeds than his opponent when the game ends wins the match\n"
        << "\t- if both players have captured the same amount of seeds at the end, the match is said to have ended in a draw\n\n";
    setColor(9);
    cout << "\t3) COLLECT PHASE\n\n"; 
    setColor(15);
    cout << "\t- the player who is to move chooses one of the holes on his own side of the board and collects all the seeds on it, leaving the hole empty\n"
        << "\t- a player may collect the seeds from any of the holes that belong to him if it contains one or more seeds\n"
        << "\t- a move that would leave all the holes empty on the opponent's side is not legal\n"
        << "\t- after making the move his opponent must be able to play\n\n";
    setColor(9);
    cout << "\t4) SOW PHASE\n\n"; 
    setColor(15);
    cout << "\t- the player distributes the seeds collected in the first phase along the board in a counterclockwise direction\n"
        << "\t- the seeds are distributed one at a time in each of the playing holes, never dropping a seed in the hole from which the seeds were collected\n\n";
    setColor(9);
    cout << "\t5) CAPTURE PHASE\n\n"; 
    setColor(15);
    cout << "\t- when the last sown seed is dropped in one of the holes belonging to the opponent, and after dropping the seed the hole contains exactly two or three seeds, the player will capture them\n"
        << "\t- the player takes all the seeds from the hole and saves them in his own store\n"
        << "\t- the process is repeated in a clockwise direction\n"
        << "\t- players can only capture seeds from their opponents holes and never from their own holes\n"
        << "\t- if a player makes a move that would capture all the seeds on the opponent's side, that player will sow normally but will not capture any seeds\n\n\n";

    setColor(4); cout << "\t< Back to Menu? (press ENTER)"; setColor(15);
    if (cin.get() == '\n')
    {
        system("cls");
        return;
    }
}

void aboutOware()
{
    cout << endl << endl;
    cout << "\tOware is perhaps the most widespread game in the mancala family of games.\n\n"
        << "\tConsidered the national game of Ashanti City-State, Oware is said to derive\n"
        << "\tits name, which literally means 'he/she marries', from a legend about a man\n"
        << "\tand a woman who played the game endlessly and, so they could stay together \n"
        << "\tand continue playing, they married.\n\n"
        << "\tReflecting traditional African values, players of Oware encourage participa-\n"
        << "\ttion by onlookers, making it perhaps the most social two-player abstract. In\n"
        << "\trecreational play, it is  normal for spectators to discuss the game in pro- \n"
        << "\tgress and to advise the players. Games may provide a focus for entertainment\n"
        << "\tand meeting others. The game, or variations of it, also had an important ro-\n"
        << "\tle in teaching arithmetic to African children.\n\n\n";

    setColor(4); cout << "\t< Back to Menu? (press ENTER)"; setColor(15);
    if (cin.get() == '\n')
    {
        system("cls");
        return;
    }
}

int main()
{
    // amount of seeds at each hole for both north (line 0) and south (line 1) players
    int board[6][6] = { { 4,4,4,4,4,4 }, { 4,4,4,4,4,4 } }; 

    // amount of seeds at both south and north stores, the player who has captured more seeds on his store wins the game
    int southStore = 0, northStore = 0;

    // this will indicate where each player stands on the board
    // the indexes represented those two variables doesn't match the actual indexes on the array that represents the board
    // 0(A), 1(B), 2(C), 3(D), 4(E), 5(F), 6(a), 7(b), 8(c), 9(d), 10(e), 11(f) 
    // this allow a easier iteration over the board */
    int currentSouthIndex, currentNorthIndex;

    // numerical correspondence for the hole char
    int chosenHole;

    // seeds that the player collected, in the collect phase, and "keeps on his hand" until next phase, namely sow phase
    int southHand, northHand; 
    
    // south player (1), north player (-1)
    // after each move, the player will change
    int currentPlayer = 1; 

    // menu related variables
    int menuOp;
    bool validOp = true;
    bool start = false;
    bool exit = false;

    do
    {
        do
        {
            cout << endl << endl;
            setColor(9);
            cout << "\t              WELCOME TO OWARE!             \n\n";
            setColor(15);
            cout << "\t===========================================\n"
                << "\t|                                         |\n"
                << "\t|              "; setColor(9); cout << "1. Start Game              "; setColor(15); cout << "| \n"
                << "\t|              "; setColor(9); cout << "2. Game Rules              "; setColor(15); cout << "| \n"
                << "\t|              "; setColor(9); cout << "3. About Oware             "; setColor(15); cout << "| \n"
                << "\t|              "; setColor(9); cout << "4. Exit                    "; setColor(15); cout << "| \n"
                << "\t|                                         |\n"
                << "\t===========================================\n\n";

            do
            {
                cout << "\tWhat do you want to do? "; 
                cin >> menuOp;

                if (cin.fail() || (menuOp != 1 && menuOp != 2 && menuOp != 3 && menuOp != 4))
                {
                    cin.clear();
                    cin.ignore(1000000000000000000, '\n');
                    validOp = false;
                    cout << "\tInvalid option.\n";
                }
                else
                    validOp = true;

            } while (!validOp);

            cin.ignore(1000000000000000000, '\n'); // removes '\n' from the buffer to prevent it from interfer with cin.get()

            switch (menuOp)
            {
            case 1:
                cout << "\tAre you ready to play the game?\n"
                    << "\tPress ENTER to START...";

                if (cin.get() == '\n')
                {
                    system("cls");
                    start = true;
                }
                else
                    system("cls"); // initial menu will be shown again
                break;

            case 2:
                system("cls");
                gameRules();
                break;

            case 3:
                system("cls");
                aboutOware();
                break;

            case 4:
                cout << "\tAre you sure you want to exit the game?\n"
                    << "\tPress ENTER to EXIT...";

                if (cin.get() == '\n')
                    return 0;
                else
                    system("cls"); // initial menu will be shown again
                break;
            }
        } while (!start);

        while ((southStore != 24 && northStore != 24) && (southStore < 25 && northStore < 25))
        {
            cout << endl << endl;
            cout << "\tCurrent Player: ";
            if (currentPlayer == 1)
            {
                setColor(4);
                cout << "South Player\n\n";
                setColor(15);
            }
            else
            {
                setColor(9);
                cout << "North Player\n\n";
                setColor(15);
            }

            boardDisplay(board, southStore, northStore);

            collect(currentPlayer, chosenHole, currentSouthIndex, currentNorthIndex, board, southHand, northHand);

            sow(currentPlayer, chosenHole, currentSouthIndex, currentNorthIndex, board, southHand, northHand);

            capture(currentPlayer, currentSouthIndex, currentNorthIndex, southStore, northStore, board);

            cout << "\tNext Player -> PRESS ENTER"; // the board won't be updated until the players presses ENTER

            if (cin.get() == '\n')
            {
                currentPlayer = currentPlayer * -1;
                system("cls");
            }  
        }

        if (southStore == 24 && northStore == 24) // draw 
        {
            setColor(9);
            cout << "\tGAME OVER. The game has just ended in a draw.\n\n";
            cout << "\tMaybe try a rematch with the next game...\n\n";
        } 
        else if (southStore < 25 && northStore >= 25) // north player wins
        {
            setColor(14);
            cout << "\tCONGRATULATION TO NORTH PLAYER, THE WINNER!\n\n";
            setColor(4);
            cout << "\tSorry South Player, try again next time...\n\n";
        }
        else if (southStore >= 25 && northStore < 25) // south player wins
        {
            setColor(14);
            cout << "\tCONGRATULATION TO SOUTH PLAYER, THE WINNER!\n\n";
            setColor(4);
            cout << "\tSorry North Player, try again next time...\n\n";
        }

        cout << "\tMenu: ENTER\n"
            << "\tExit: CTRL-Z\n";

        if (cin.eof())
            exit = true;

    } while (!exit);

    return 0;
}