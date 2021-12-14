#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include "drawmap.c"
HANDLE consoleHandle;
int w = 100;
int h = 50;
void gotoxy(int x,int y){
    COORD co = (COORD){.X = x, .Y = y};
    SetConsoleCursorPosition(consoleHandle,co);
}
void game1(int w,int h,char **map){
    system("cls");
    drawmap(map,w,h);
    gotoxy(w/2 - 10,1);
    printf("welcome to game1!\n");
    gotoxy(w / 2 - 15,48);
    printf("Press q if you want to quit");
    gotoxy(w/2 - 10,2);
    printf("rock : press 1; scissors : press 2; paper : press 3");
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize = 100;
    cci.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle,&cci);
    while (1){
        while (kbhit() != 0){

//rand
            char c = getch();
            if(c == 'q'){
                return;
            }
        }
    }
}
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
    int flag = 0;
    while(1) {
        while (kbhit() != 0) {
            char c = getch();
            if(c == '1'){
                game1(w,h,map);
                system("cls");
                goto RET;
            }else if(c == 'q'){
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