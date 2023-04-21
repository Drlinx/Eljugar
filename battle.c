#include "game.h"

/**
 * @param attacking enemy mon that is currently out.
 * @param defending mon that is defending.
 * @param fight attacking mons move.
 */
int attack (struct team *attacking, struct team *defending, struct move *fight){
    int hit = 0;
    int damage;
    // Makes sure we have move uses left
    if (fight->uses == 0){
        printf("%s's %s is out of uses!\n", attacking->out->name, fight->name);
        return 1;
    }
    fight->uses -= 1;
    
    hit = rand() % 100;
    // If move hits
    if (hit <= fight->accuracy){
        damage = (attacking->out->attack * fight->damage)/defending->out->defense;
        damage = damage * masterte(fight, defending->out);
        defending->out->hp = defending->out->hp - damage;
        printf("%s took %d damage!", defending->out->name, damage);
        return 2;
    } else {
        printf("%s's attack failed", attacking->out->name);
        return 3;
    }
}

/**
 * 
 * @param defending Checking if it was KO'd
 * 
 * @brief determines if the defending mon was KO'd
 * 
 */
int KO (struct team *defending){
    if(defending->out->hp > 0){
        return IN;
    } 
    defending->out->awake = OUT;
    printf("%s has been knocked out!", defending->out->name);
    switchlead(defending);
    return OUT;

}

/**
 * @param change the team that is changing their mon.
 * 
 * @brief changes the currently out summon in the team.
 */
int switchlead (struct team *change){
    char *input[128];
    printf("Who are we switching to?");
    if (change->sum1->name == IN && change->sum1 != NULL){
        printf("1. %s\n", change->sum1->name);
    }
    if (change->sum2->name == IN && change->sum2 != NULL){
        printf("2. %s\n", change->sum2->name);
    }
    if (change->sum3->name == IN){
        printf("3. %s\n", change->sum3->name && change->sum3 != NULL);
    }
    if (change->sum4->name == IN){
        printf("4. %s\n", change->sum4->name && change->sum4 != NULL);
    }
    if (change->sum5->name == IN && change->sum5 != NULL){
        printf("5. %s\n", change->sum5->name);
    }
    

    fgets(input, 128, stdin);
    if (input[0] == '1' && change->sum1->awake == IN && change->sum1 != NULL){
        change->out = change->sum1;
    } else if (input[0] == '2' && change->sum2->awake == IN && change->sum2 != NULL){
        change->out = change->sum2;
    } else if (input[0] == '3' && change->sum3->awake == IN && change->sum3 != NULL){
        change->out = change->sum3;
    } else if (input[0] == '4' && change->sum4->awake == IN && change->sum4 != NULL){
        change->out = change->sum4;
    } else if (input[0] == '5' && change->sum5->awake == IN && change->sum5 != NULL){
        change->out = change->sum5;
    } else {
        printf("Invalid choice.");
        switchlead(change);
        return 1;
    }
    printf("Go %s!");
    return 0;
}