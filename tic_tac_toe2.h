#include <stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <windows.h>
#define ROWS 3
#define COLS 3
typedef char Board[ROWS][COLS];
void printBoard(Board board)
{
    gotoxy(40,8);
    printf("\n\n");
    printf("\t\t\t\t  %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
    printf("\t\t\t\t ---|---|---\n");
    printf("\t\t\t\t  %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
    printf("\t\t\t\t ---|---|---\n");
    printf("\t\t\t\t  %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
}

int hasWinner(Board board)
{
    int line;
    if((board[0][0]==board[1][1] && board[0][0]==board[2][2]) ||
            (board[0][2]==board[1][1] && board[0][2]==board[2][0]))
    {
        return 1;
    }
    for(line = 0; line <=2; line++)
    {
        if((board[line][0]==board[line][1] && board[line][0]==board[line][2])||
                (board[0][line]==board[1][line] && board[0][line]==board[2][line]))
        {
            return 1;
        }
    }
    return 0;
}
void print()
{
    printf("**intsructions\n");
    printf("\n\n->Here in tac-tic-toe multi player\n\n-> player 1 plays with X \n\n-> player 2 plays with O\n\npress any key to continue\n\n ");
    getch();
    system("cls");
}
void tic_tac_toe2()
{
    int winner = 0;
    int choice = 0;
    int row = 0;
    int column = 0;
    int line = 0;
    int i;
    print();
    Board board =
    {
        {'1','2','3'},
        {'4','5','6'},
        {'7','8','9'}
    };


    for (i = 0; i<9 && !winner; i++)
    {
        int player = i%2 + 1;
        printBoard(board);

        do
        {
            printf("\nPlayer %d, please enter the number of the square \n"
                   "where you want to place your %c: ",
                   player,(player==1)?'X':'O');
            scanf("%d", &choice);
            system("cls");
            row = --choice/3;
            column = choice%3;
        }
        while(choice<0 || choice>9 || board [row][column]>'9');

        board[row][column] = (player == 1) ? 'X' : 'O';
        if (hasWinner(board)==1)
        {
            winner = player;
        }
    }

    printBoard(board);

    if(!winner)
    {
        printf("The game is a draw\n");
    }
    else
    {
        printf("Player %d has won\n", winner);
    }

    exit(0);
}
