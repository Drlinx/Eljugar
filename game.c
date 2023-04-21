#include "game.h"


int main(){
    int x = WATER;
    printf("%d", x);
    int lead;
    int end = GO;
    
    FILE *p1, *p2;

    struct team player;
    struct team ai;
    struct summon *playero;
    struct summon *aio;

    p1 = fopen("./teams/ptest", "r");
    p2  = fopen("./teams/atest.txt", "r");

    while (end == GO){
        if (aio->speed > playero->speed){
            lead = AI;
        } else {
            lead = PLAYER;
        }

        switch(lead){
            case AI:
                aiturn();
                break;
            case PLAYER:
                playerturn();
                break;
            default:
                printf("Error | Turn order broken.");
                end = A;
                break;
        }
    }

    return 0;
}


int playerturn(){
    return 0;
}

int aiturn(){
    return 0;
}