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
    int HP;
    int power;
}Player;
void gotoxy(int x,int y){
    COORD co = (COORD){.X = x, .Y = y};
    SetConsoleCursorPosition(consoleHandle,co);
}
void reset(Player *m,Player *n);
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
                gotoxy(w / 2 - 10,26);
                system("pause");
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
                gotoxy(w / 2 - 10,26);
                system("pause");
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
                gotoxy(w / 2 - 10,26);
                system("pause");
            }
            goto RET1;
        }
    }
}
void game2(char **map){
    CONSOLE_CURSOR_INFO cci;
    cci.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle,&cci);
    Player you,computer;
    reset(&you,&computer);
    RET2: system("cls");
    //RET2: 重启游戏2
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
    gotoxy(3,6);
    printf("%s",computer.name);
    gotoxy(3,7);
    printf("HP: %d",computer.HP);
    gotoxy(3,8);
    printf("power: %d",computer.power);
    gotoxy(w - 12,6);
    printf("%s",you.name);
    gotoxy(w - 12,7);
    printf("HP: %d",you.HP);
    gotoxy(w - 12,8);
    printf("power: %d",you.power);
    /**
     * 打印完了该打印的信息
     */
    while (1){
        while (kbhit() != 0){
            char c = getch();
            int com = 0;
            RET3: com = ComputerChoice();//产生随机数
            if(computer.power == 0 && com == 2)goto RET3;
            if(you.power == 0 && com == 3)goto RET3;
            if(computer.power >= 80 && (com == 1 || com == 3))goto RET3;
            /**
             * 防止出现没有能量电脑却攻击的情况
             * 防止出现玩家没能量，电脑却防守的情况
             * 尽量避免电脑拼命积攒能量的情况
             */
            if(c == 'q'){
                return;
            }else if(c == '1'){
                you.power += 10;
                if(com == 1){
                    computer.power += 10;
                }else if(com == 2){
                    you.HP -= 10;
                    if(you.HP <= 0){
                        gotoxy(w - 7,7);
                        printf("\b\b %d  ",you.HP);
                        gotoxy(w / 2 - 5,24);
                        printf("You lose!");
                        system("pause");
                        reset(&you,&computer);
                        goto RET2;
                    }
                }
            }else if(c == '2'){
                if(you.power == 0){
                    you.HP = 0;
                    gotoxy(w - 7,7);
                    printf("\b\b %d  ",you.HP);
                    gotoxy(w / 2 - 5,24);
                    printf("You lose!");
                    system("pause");
                    reset(&you,&computer);
                    /**
                     * 能量不够，憋死了
                     */
                }else if(you.power != 0 && com == 1){
                    computer .HP -= 10;
                    you .power -= 10;
                    computer.power += 10;
                    if(computer.HP == 0){
                        gotoxy(8,7);
                        printf("\b\b %d  ", computer.HP);
                        gotoxy(w / 2 - 5,24);
                        printf("You win!");
                        system("pause");
                        reset(&you,&computer);
                    }
                }else if(you.power != 0 && com == 2){
                    you.power -= 10;
                    computer .power -= 10;
                    you.HP -= 10;
                    computer .HP -= 10;
                    if(you.HP == 0 && computer.HP != 0){
                        gotoxy(w - 7,7);
                        printf("\b\b %d  ",you.HP);
                        gotoxy(w / 2 - 5,24);
                        printf("You lose!");
                        system("pause");
                        reset(&you,&computer);
                    }else if(computer .HP == 0 && you.HP != 0){
                        gotoxy(8,7);
                        printf("\b\b %d  ", computer.HP);
                        gotoxy(w / 2 - 5,24);
                        printf("You win!");
                        system("pause");
                        reset(&you,&computer);
                    }else if(computer.HP == 0 && you.HP == 0){
                        gotoxy(8,7);
                        printf("\b\b %d  ", computer.HP);
                        gotoxy(w - 7,7);
                        printf("\b\b %d  ",you.HP);
                        gotoxy(w / 2 - 2,24);
                        printf("Draw!");
                        system("pause");
                        reset(&you,&computer);
                    }
                } else if(you.power != 0 && com == 3){
                    you.power -= 10;
                }
                goto RET2;
            }else if(c == '3'){
                if(com == 1){
                    computer.power += 10;
                }else if(com == 2){
                    computer.power -= 10;
                }
                goto RET2;
            }
            /**
             * 1.积攒能量
             * 2.攻击
             * 3.防御
             */
            goto RET2;
        }
    }
}
void reset(Player *m,Player *n){
    m -> name = "You";
    m -> HP = 100;
    m -> power = 0;
    n -> name = "Computer";
    n -> HP = 100;
    n -> power = 0;
}
