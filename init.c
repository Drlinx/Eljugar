#include "game.h"

/**
 * @param team the file loation we are using for creating the player's team
 * @param player the struct containing the players team's data.
 * 
 * @brief This initalizes an entire team for battle. 
 * 
 */
int initteam(FILE *team, struct team *player){
    char *data;
    data = malloc(1024);
    teammal(player);

    // Init's basic team info
    fgets(data, 1024, team);
    nl_rm(data);
    player->name = data;
    fgets(data, 1024, team);
    nl_rm(data);
    player->AI = atoi(data);

    sumbuild(player, data, team);
    
    free(data);
    return 0;
}


/**
 * @param player players team we are building.
 * @param data string of lines read.
 * @param team file pointer.
 * 
 * @brief Does most of the function calls for building the team members
 */
int sumbuild(struct team *player, char *data, FILE *team){
    player->sum1 = malloc(sizeof(struct summon));
    player->sum2 = malloc(sizeof(struct summon));
    player->sum3 = malloc(sizeof(struct summon));
    player->sum4 = malloc(sizeof(struct summon));
    player->sum5 = malloc(sizeof(struct summon));

    fgets(data, 1024, team);
    nl_rm(data);
    player->KOS += initsummon(data, player->sum1);

    fgets(data, 1024, team);
    nl_rm(data);
    player->KOS += initsummon(data, player->sum2);
    
    fgets(data, 1024, team);
    nl_rm(data);
    player->KOS += initsummon(data, player->sum3);
    
    fgets(data, 1024, team);
    nl_rm(data);
    player->KOS += initsummon(data, player->sum4);
    
    fgets(data, 1024, team);
    nl_rm(data);
    player->KOS += initsummon(data, player->sum5);
}


/**
 * @param summons the name of the summon
 * @param sum the struct of the summon.
 * @param data the file stream we created in the team init function.
 * 
 * @brief Builds struct for each Summon.
 */
int initsummon(char *summons, struct summon *sum){
    char *path = malloc(1024);
    path = "./summons/";
    strcat(path, summons);
    strcat(path, ".txt");
    FILE *mon = fopen(path, "r");
    if (mon == NULL){
        sum = NULL;
        return -1;
    }
    sum->name = malloc(strlen(summons));
    sum->name = summons;

    // Do later.
    sum->sprite = NULL;

    fgets(path, 1024, mon);   
    sum->hp = atoi(path);
    fgets(path, 1024, mon);  
    sum->attack = atoi(path);
    fgets(path, 1024, mon);  
    sum->defense = atoi(path);
    fgets(path, 1024, mon);  
    sum->speed = atoi(path);
    fgets(path, 1024, mon);  
    sum->type = atoi (path); 
    fgets(path, 1024, mon);  
    sum->awake = atoi(path);
    movebuild(sum, path, mon);
    close(mon);
    free(path);
    return 0;
}


/**
 * 
 * @param player the mon we are adding the moves to.
 * @param data the char buffer we are using.
 * @param team the file we are currently reading.
 * 
 * @brief Starts the process for init move for each move slot.
 * 
 */
int movebuild(struct summon *player, char *data, FILE *team){

    player->slot1 = malloc(sizeof(struct summon));
    player->slot2 = malloc(sizeof(struct summon));
    player->slot3 = malloc(sizeof(struct summon));
    player->slot4 = malloc(sizeof(struct summon));

    fgets(data, 1024, team);
    nl_rm(data);
    initmove(data, player->slot1);

    fgets(data, 1024, team);
    nl_rm(data);
    initmove(data, player->slot2);
    
    fgets(data, 1024, team);
    nl_rm(data);
    initmove(data, player->slot3);
    
    fgets(data, 1024, team);
    nl_rm(data);
    initmove(data, player->slot4);


    return 0;
}


/**
 * 
 * @param name the moves name.
 * @param use the move struct we are initalizing.
 * 
 * @brief Adds the data for the move slot.
 * 
 */
int initmove(char *name, struct move *use){
    char *path = malloc(1024);
    path = "./moves/";
    ws_rp(name);
    strcat(path, name);
    strcat(path, ".txt");
    FILE *mov = fopen(path, "r");
    if (mov == NULL){
        use = NULL;
        return -1;
    }
    use->name = name;
    fgets(path, 1024, mov);
    use->damage = atoi(path);
    fgets(path, 1024, mov);
    use->accuracy = atoi(path);
    fgets(path, 1024, mov);
    use->type = atoi(path);
    fgets(path, 1024, mov);
    use->uses = atoi(path); 


    free(path);
    close(mov);
    return 0;
}