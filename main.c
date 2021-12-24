#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include "drawmap.c"
#include "computer_choice.c"
#include "quiz.c"
HANDLE consoleHandle;
int w = 100;
int h = 50;
CONSOLE_CURSOR_INFO cci;
typedef struct player{
    char *name;
    int HP;
    int power;
}Player;
void gotoxy(int x,int y){
    COORD co = (COORD){.X = x, .Y = y};
    SetConsoleCursorPosition(consoleHandle,co);
}
void reset(Player *m,Player *n,int *count);
int computer_logic(int power1,int hp1,int power2,int hp2,int random);
void PrintLastRound(int last_player,int last_com);
void game1(char **map);
void game2(char **map);
void game3(char **map);
void game4(char **map);
int main() {
    consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    system("color F3");
    char **map = malloc(h * sizeof(char *));
    for (int i = 0; i < h; i++) {
        *(map + i) = malloc((w + 1) * sizeof(char));
    }
    for (int i = 0; i < h; i++) {
        memset(*(map + i),0,w + 1);
    }
    RET:    drawmap(map,w,h);
    gotoxy(w / 2 - 25,1);
    printf("Welcome to 99in1! Miku has 3 games for you to choose.");
    gotoxy(w/2 - 12,23);
    printf("1. Finger-guessing");
    gotoxy(w/2 - 12,24);
    printf("2. Clapping game");
    gotoxy(w/2 - 12,25);
    printf("3. Squid game");
    gotoxy(w / 2 - 12,26);
    printf("4. Miku's little quiz");
    gotoxy(w / 2 - 24,47);
    printf("Press 1, 2, 3 or 4 to choose a game to play.");
    gotoxy(w / 2 - 15,48);
    printf("Press q if you want to quit");
    srand((unsigned)time(NULL));
    int flag = 0;
    while(1) {
        cci.dwSize = 100;
        cci.bVisible = FALSE;
        SetConsoleCursorInfo(consoleHandle,&cci);
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
            }else if(c == '3'){
                game3(map);
                system("cls");
                goto RET;
            }else if(c == '4'){
                game4(map);
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
    system("cls");
    drawmap(map,w,h);
    gotoxy(w / 2 - 7,23);
    printf("Miku will miss you...");
    Sleep(2000);
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
    Player you,computer;
    int count = 1;
    int last_player = 1;
    int last_com = 1;
    reset(&you,&computer,&count);
    count++;
    RET2: system("cls");
    //RET2: 重启游戏2
    drawmap(map,w,h);
    gotoxy(w / 2 - 15,1);
    printf("Welcome to Clapping game");
    gotoxy(w / 2 - 30,2);
    printf("You have 3 choices: press 1 if you want to gain power");
    gotoxy(w / 2 - 15,3);
    printf("press 2 if you want to attack");
    gotoxy(w / 2 - 15,4);
    printf("press 3 if you want to defend");
    gotoxy(w / 2 - 35 ,5);
    printf("Warning: If your power is zero and you choose to attack, then you lose");
    gotoxy(w / 2 - 8,6);
    printf("Round %d",count);
    gotoxy(w / 2 - 15,48);
    printf("Press q if you want to quit");
    gotoxy(w / 2 - 16,47);
    printf("Press r if you want to resume");
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
     if(count > 1){
         PrintLastRound(last_player,last_com);
     }
    while (1){
        while (kbhit() != 0){
            char c = getch();
            int com;
            int com_init;
            RET3: com_init = ComputerChoice();//产生随机数
            com = computer_logic(computer.power, computer.HP,you.power,you.HP,com_init);
            if(computer.power == 0 && com == 2)goto RET3;
            if(you.power == 0 && com == 3)goto RET3;
            if(computer.power >= 80 && (com == 1 || com == 3))goto RET3;
            /**
             * 防止出现没有能量电脑却攻击的情况
             * 防止出现玩家没能量，电脑却防守的情况
             * 尽量避免电脑拼命积攒能量的情况
             */
             last_com = com;
            if(c == 'q'){
                return;
            }else if(c == '1'){
                you.power += 10;
                last_player = 1;
                if(com == 1){
                    computer.power += 10;
                }else if(com == 2){
                    you.HP -= 10;
                    computer.power -= 10;
                    if(you.HP <= 0){
                        gotoxy(w - 7,7);
                        printf("\b\b %d  ",you.HP);
                        gotoxy(w / 2 - 5,24);
                        printf("You lose!");
                        system("pause");
                        reset(&you,&computer,&count);
                    }
                }
            }else if(c == '2'){
                last_player = 2;
                if(you.power == 0){
                    you.HP = 0;
                    gotoxy(w - 7,7);
                    printf("\b\b %d  ",you.HP);
                    gotoxy(w / 2 - 5,24);
                    printf("You lose!");
                    system("pause");
                    reset(&you,&computer,&count);
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
                        reset(&you,&computer,&count);
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
                        reset(&you,&computer,&count);
                    }else if(computer .HP == 0 && you.HP != 0){
                        gotoxy(8,7);
                        printf("\b\b %d  ", computer.HP);
                        gotoxy(w / 2 - 5,24);
                        printf("You win!");
                        system("pause");
                        reset(&you,&computer,&count);
                    }else if(computer.HP == 0 && you.HP == 0){
                        gotoxy(8,7);
                        printf("\b\b %d  ", computer.HP);
                        gotoxy(w - 7,7);
                        printf("\b\b %d  ",you.HP);
                        gotoxy(w / 2 - 2,24);
                        printf("Draw!");
                        system("pause");
                        reset(&you,&computer,&count);
                    }
                } else if(you.power != 0 && com == 3){
                    you.power -= 10;
                }
            }else if(c == '3'){
                last_player = 3;
                if(com == 1){
                    computer.power += 10;
                }else if(com == 2){
                    computer.power -= 10;
                }
            }else if(c == 'r'){
                reset(&you,&computer,&count);
            }
            /**
             * 1.积攒能量
             * 2.攻击
             * 3.防御
             */
             count++;
            goto RET2;
        }
    }
}
void game3(char **map){
    cci.bVisible = TRUE;
    SetConsoleCursorInfo(consoleHandle,&cci);
    RET4 : system("cls");
    drawmap(map,w,h);
    gotoxy(w / 2 - 15,48);
    printf("Press q if you want to quit");
    gotoxy(w / 2 - 10,1);
    printf("Welcome to Squid game!");
    gotoxy(w / 2 - 21,2);
    printf("Everytime you will have two lattices to jump.");
    gotoxy(w / 2 - 18,3);
    printf("one means life and another means death.");
    gotoxy(w / 2 - 21,4);
    char str[10] = {0};
    int lines;
    printf("Choose how many times you want to experience.");
    gotoxy(w / 2 - 8,5);
    printf("Type a number:");
    scanf("%s",str);
    if(str[0] != 'q'){
        sscanf(str,"%d",&lines);
    }else{
        cci.bVisible = FALSE;
        SetConsoleCursorInfo(consoleHandle,&cci);
        return;
    }
    system("cls");
    gotoxy(10,0);
    printf("Press 1 or 2, or q if you want to quit");
    for (int i = 1; i <= lines ; i++) {
        gotoxy(24,i);
        printf("* *");
    }
    gotoxy(0,0);
    for (int i = 1; i <= lines ; i++) {
        int random = rand()%2 + 1;
        char c = (char) getch();
        if(c == '1' && random == 2){
            gotoxy(24,i);
        }else if(c == '1' && random == 1){
            gotoxy(18 , i);
            printf("You die!");
            system("pause");
            goto RET4;
        }else if(c == '2' && random == 1){
            gotoxy(26,i);
        }else if(c == '2' && random == 2){
            gotoxy(18 , i);
            printf("You die!");
            system("pause");
            goto RET4;
        }
        else if(c == 'q'){
            cci.bVisible = FALSE;
            SetConsoleCursorInfo(consoleHandle,&cci);
            return;
        }else{
            i--;
        }
    }
    system("cls");
    drawmap(map,w,h);
    gotoxy(w / 2 - 6, h / 2 - 1);
    printf("You are alive!");
    system("pause");
    goto RET4;
    /**
     * 记得返回目录前再次隐藏光标
     */
}
void game4(char **map){
    int score = 0;
    int i = 0;
    while (i < 20){
        system("cls");
        drawmap(map,w,h);
        gotoxy(w / 2 - 15,48);
        printf("Press q if you want to quit");
        gotoxy(w / 2 - 17,1);
        printf("Miku has a little quiz for you!");
        gotoxy(w / 2 - 17,22);
        printf("%s",miku_quiz[i].question);
        gotoxy(w / 2 - 17,23);
        printf("%s",miku_quiz[i].choice1);
        gotoxy(w / 2 - 17,24);
        printf("%s",miku_quiz[i].choice2);
        gotoxy(w / 2 - 17,25);
        printf("%s",miku_quiz[i].choice3);
        char ch;
        Error_input:
        ch = getch();
        if(ch == 'q'){
            return;
        }else if(ch == '1' || ch == '2' || ch == '3'){
            if(ch - 48 == miku_quiz[i].right_choice){
                score += 5;
            }
        }else{
            goto Error_input;
        }
        i++;
    }
    system("cls");
    drawmap(map,w,h);
    gotoxy(w / 2 - 10,24);
    printf("Your score is %d",score);
    if(score >= 80){
        gotoxy(w / 2 - 11,25);
        printf("Wow! Miku loves you!");
    }else if(score >= 50 && score < 80){
        gotoxy(w / 2 - 19,25);
        printf("Not bad. Miku wants you to learn more!");
    } else{
        gotoxy(w / 2 - 21,25);
        printf("Emmm... Miku hopes that you'll love ACG one day.");
    }
    Sleep(3000);
    return;
}
void reset(Player *m,Player *n,int *count){
    m -> name = "You";
    m -> HP = 100;
    m -> power = 0;
    n -> name = "Computer";
    n -> HP = 100;
    n -> power = 0;
    *count = 0;
}
void PrintLastRound(int last_player,int last_com){
    gotoxy(w/2 - 18,23);
    if(last_player == 1 && last_com == 1){
        printf("Computer:gain power   You:gain power");
    }else if(last_player == 1 && last_com == 2){
        printf("Computer:attack   You:gain power");
    }else if(last_player == 1 && last_com == 3){
        printf("Computer:defend   You:gain power");
    }else if(last_player == 2 && last_com == 1){
        printf("Computer:gain power   You:attack");
    }else if(last_player == 2 && last_com == 2){
        printf("Computer:attack   You:attack");
    }else if(last_player == 2 && last_com == 3){
        printf("Computer:defend   You:attack");
    } else if(last_player == 3 && last_com == 1){
        printf("Computer:gain power   You:defend");
    }else if(last_player == 3 && last_com == 2){
        printf("Computer:attack   You:defend");
    }else if(last_player == 3 && last_com == 3){
        printf("Computer:defend   You:defend");
    }
}
int computer_logic(int power1,int hp1,int power2,int hp2,int random){
    if(power1 - power2 <= 20 && power1 - power2 >= -20 ){
        if(1 <= random && random <= 3){
            return 1;
        }else if(4 <= random && random <= 6){
            return 2;
        }else if(7 <= random && random <= 9){
            return 3;
        }
    }else if(power1 - power2 > 20 && hp1 >= hp2 ){
        if(1 <= random && random <= 2){
            return 1;
        }else if(3 <= random && random <= 8){
            return 2;
        }else if(random == 9){
            return 3;
        }
    }else if(power1 - power2 > 20 && hp1 < hp2){
        if(1 <= random  && random <= 2){
            return 1;
        }else if(3 <= random && random <= 7){
            return 2;
        }else if(8 <= random && random <= 9){
            return 3;
        }
    }else if(power2 - power1 > 20 && hp1 > hp2){
        if(1 <= random && random <= 3){
            return 1;
        }else if(4 <= random && random <= 6){
            return 2;
        }else if(7 <= random && random <= 9){
            return 3;
        }
    }else if(power2 - power1 > 20 && hp1 <= hp2){
        if(1 <= random  && random <= 2){
            return 1;
        }else if(3 <= random && random <= 4){
            return 2;
        }else if(5 <= random && random <= 9){
            return 3;
        }
    }
}