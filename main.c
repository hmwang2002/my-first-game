#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include "drawmap.c"
#include "computer_choice.c"
HANDLE consoleHandle;
int w = 100;
int h = 50;
typedef struct player{
    char *name;
    int blood;
    int power;
}Player;
void gotoxy(int x,int y){
    COORD co = (COORD){.X = x, .Y = y};
    SetConsoleCursorPosition(consoleHandle,co);
}
void game1(char **map);
void game2(char **map);
int main() {
    consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

    char **map = malloc(h * sizeof(char *));
    for (int i = 0; i < h; i++) {
        *(map + i) = malloc((w + 1) * sizeof(char));
    }
    for (int i = 0; i < h; i++) {
        memset(*(map + i),0,w + 1);
    }
    RET:    drawmap(map,w,h);
    gotoxy(w / 2 - 27,1);
    printf("Welcome to 99in1! There have 3 games for you to choose.");
    gotoxy(w/2 - 8,23);
    printf("1. Finger-guessing");
    gotoxy(w/2 - 8,24);
    printf("2. Clapping game");
    gotoxy(w/2 - 8,25);
    printf("3. Squid game");
    gotoxy(w / 2 - 18,47);
    printf("Press 1, 2, 3 to choose a game to play.");
    gotoxy(w / 2 - 15,48);
    printf("Press q if you want to quit");
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize = 100;
    cci.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle,&cci);
    srand((unsigned)time(NULL));
    int flag = 0;
    while(1) {
        while (kbhit() != 0) {
            char c = getch();
            if(c == '1'){
                game1(map);
                system("cls");
                goto RET;
            }else if(c == '2'){
                game2(map);
                system("cls");
                goto RET;
            }
            else if(c == 'q'){
                flag = 1;
                break;
            }

        }
        if(flag == 1){
            break;
        }
    }
    cci.bVisible = TRUE;
    SetConsoleCursorInfo(consoleHandle,&cci);
    free(map);
}
void game1(char **map){
    RET1: system("cls");
    drawmap(map,w,h);
    gotoxy(w/2 - 20,1);
    printf("Welcome to game1: Finger guessing!");
    gotoxy(w / 2 - 15,48);
    printf("Press q if you want to quit");
    gotoxy(w/2 - 27,2);
    printf("rock : press 1; scissors : press 2; paper : press 3");
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize = 100;
    cci.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle,&cci);
    while (1){
        while (kbhit() != 0){
            int computer = ComputerChoice();
            //产生随机数
            char c = getch();
            if(c == 'q'){
                return;
            }else if( (c == '1' && computer == 1 )||(c == '2' && computer == 2) || (c == '3' && computer == 3)){
                gotoxy(w/2 - 7,24);
                printf("Draw! Play again!");
                gotoxy(w/2 - 13,25);
                if(c == '1'){
                    printf("Computer: rock   You: rock");
                }else if(c == '2'){
                    printf("Computer: scissors   You: scissors");
                }else if(c == '3'){
                    printf("Computer: paper   You: paper");
                }
                Sleep(2000);
                //暂停2s
            }else if((c == '1' && computer == 2) || (c == '2' && computer == 3) || (c == '3' && computer == 1)){
                gotoxy(w/2 - 7,24);
                printf("Good job! You win!");
                gotoxy(w/2 - 13,25);
                if(c == '1'){
                    printf("Computer: scissors   You: rock");
                }else if(c == '2'){
                    printf("Computer: paper   You: scissors");
                }else if(c == '3'){
                    printf("Computer: rock   You: paper");
                }
                Sleep(2000);
            }else if((c == '1' && computer == 3) || (c == '2' && computer == 1) || (c == '3' && computer == 2)){
                gotoxy(w/2 - 7,24);
                printf("Sorry. You lose.");
                gotoxy(w/2 - 13,25);
                if(c == '1'){
                    printf("Computer: paper   You: rock");
                }else if(c == '2'){
                    printf("Computer: rock   You: scissors");
                }else if(c == '3'){
                    printf("Computer: scissors   You: paper");
                }
                Sleep(2000);
            }
            goto RET1;
        }
    }
}
void game2(char **map){
    CONSOLE_CURSOR_INFO cci;
    cci.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle,&cci);
    RET2: system("cls");
    drawmap(map,w,h);
    gotoxy(w / 2 - 10,1);
    printf("Welcome to Clapping game");
    gotoxy(w / 2 - 25,2);
    printf("You have 3 choices: press 1 if you want to gain power");
    gotoxy(w / 2 - 10,3);
    printf("press 2 if you want to attack");
    gotoxy(w / 2 - 10,4);
    printf("press 3 if you want to defend");
    gotoxy(w / 2 - 30 ,5);
    printf("Warning: If your power is zero and you choose to attack, then you lose");
    gotoxy(w / 2 - 15,48);
    printf("Press q if you want to quit");
    Player you,computer;
    you .name = "You";
    you .blood = 100;
    you .power = 0;
    computer .name = "Computer";
    computer .blood = 100;
    computer .power = 0;
    gotoxy(3,6);
    printf("%s",computer.name);
    gotoxy(3,7);
    printf("blood: %d",computer.blood);
    gotoxy(3,8);
    printf("power: %d",computer.power);
    gotoxy(w - 12,6);
    printf("%s",you.name);
    gotoxy(w - 12,7);
    printf("blood: %d",you.blood);
    gotoxy(w - 12,8);
    printf("power: %d",you.power);
    /**
     * 打印完了该打印的信息
     */
    while (1){
        while (kbhit() != 0){
            int computer = ComputerChoice();
            //产生随机数
            char c = getch();
            if(c == 'q'){
                return;
            }else if( (c == '1' && computer == 1 )||(c == '2' && computer == 2) || (c == '3' && computer == 3)){

            }else if((c == '1' && computer == 2) || (c == '2' && computer == 3) || (c == '3' && computer == 1)){

            }else if((c == '1' && computer == 3) || (c == '2' && computer == 1) || (c == '3' && computer == 2)){

            }
            goto RET2;
        }
    }
}
