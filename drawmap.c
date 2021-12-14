#include <stdio.h>
void drawmap(char **map,int w,int h){
    for (int i = 0; i < h; i++) {
        if(i == 0){
            for (int j = 0; j < w; j++) {
                map[i][j] = '*';
            }
        }else if(i == h - 1){
            for (int j = 0; j < w; j++) {
                map[i][j] = '*';
            }
        }else{
            map[i][0] = '*';
            map[i][w - 1] = '*';
            for (int j = 1; j < w - 1; j++) {
                map[i][j] = ' ';
            }
        }
    }
    for (int i = 0; i < h; i++) {
        printf("%s\n",map[i]);
    }
}
