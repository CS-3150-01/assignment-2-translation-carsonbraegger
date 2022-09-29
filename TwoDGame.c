#include <stdio.h>
#include <stdbool.h>




int main(){
        int player = 2;
        char input = 'u';
        int map[20][100] = {0}; 
        map[2][2] = player;
        bool proceed = true;
        const char *direction[4] ={"North", "East", "South", "West"};
        int dirX[] =      {      0,     -1,       0,      1};
        int dirY[]=       {      1,      0,      -1,      0};

        int currentDirection = 0;
        int currentPosition[] ={2,2};
        while(proceed){
            for(int i = 0; i<20; i++){
                for(int j=0; j<100; j++){
                    if(map[i][j] == NULL){
                        printf("*");
                    }else{
                        printf(map[i][j]);
                    }
                }
                printf("\n");
            }
            printf("Please traverse the world and explore using these commands: \n  W - Walk Forward\n  A - Turn Left\n  D - Turn Right\n  E - Check Direction\n  Q - Quit the Game");
            scanf("%c", input);
            switch(input){
                case 'w':
                map[currentPosition[1]] [currentPosition[0]]='#';
                if(!((currentPosition[0] - dirX[currentDirection] < 0) || (currentPosition[0] - dirX[currentDirection] > 100)||(currentPosition[1] - dirY[currentDirection] < 0) || (currentPosition[1] - dirY[currentDirection] > 20))){
                    currentPosition[0] = currentPosition[0] - dirX[currentDirection];
                    currentPosition[1] = currentPosition[1] - dirY[currentDirection];
            }

            map[currentPosition[1]][currentPosition[0]] = 'P';
            break;
            case 'a':
            currentDirection--;
            if(currentDirection < 0){
                currentDirection = 3;
            }
            break;
            case 'd':
            currentDirection++;
            if(currentDirection >3){
                currentDirection = 0;
            }
            break;
            case 'e':
            printf("\n You are facing in the %sward direction", direction[currentDirection]);
            break;
            case 'q':
            proceed = false;
            break;
            default:
            printf("\n You must enter one of the commands.");
        }
    }
}