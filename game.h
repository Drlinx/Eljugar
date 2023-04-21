#include <stdio.h>
#include <stdlib.h>



enum TYPE {FIRE = 0, WATER, GRASS, NORMAL};

enum STATUS {IN, OUT};

enum LEAD {AI, PLAYER};

enum GAMEEND {GO, A, P};

struct move{
    char *name;
    int damage;
    int accuracy;
    int type;
    int uses;
};

struct summon{
    char *sprite;
    char *name;
    int hp;
    int attack;
    int defense;
    int speed;
    int type;
    int awake;
    struct move *slot1;
    struct move *slot2;
    struct move *slot3;
    struct move *slot4;
};

struct team{
    char *name;
    int AI;
    int KOS;
    int ingame;

    struct summon *out;
    struct summon *sum1;
    struct summon *sum2;
    struct summon *sum3;
    struct summon *sum4;
    struct summon *sum5;
};





int attack (struct team *attacking, struct team *defending, struct move *fight);
int KO (struct team *defending);
int switchlead (struct team *change);
float masterte(struct move *atype, struct summon *dtype);
float water(struct summon *dtype);
float fire(struct summon *dtype);
float grass(struct summon *dtype);
int ai();
int initmove(char *name, struct move *use);
int movebuild(struct summon *player, char *data, FILE *team);
int initsummon(char *summons, struct summon *sum);
int sumbuild(struct team *player, char *data, FILE *team);
int initteam(FILE *team, struct team *player);