#include"tic_tac_toe1.h"
#include"tic_tac_toe2.h"
#include"tic_tac-toehead.h"
int main()
{
    HANDLE in,out;
    DWORD info;
    CONSOLE_SCREEN_BUFFER_INFO scrinfo;
    INPUT_RECORD inp;
    COORD pos= {25,17};
    int i,j;
    SetConsoleTitle("TIC_TAC_TOE");
    in=GetStdHandle(STD_INPUT_HANDLE);
    out=GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(out,&scrinfo);
    printstr(12,10,"tic-tac-toe",219,_MAGENTA);
    SetConsoleCursorPosition(out,pos);
    system("pause");
    SetConsoleCursorPosition(out,zerozero);
    initializegame();
    return 0;
}

