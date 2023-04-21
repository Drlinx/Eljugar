#include "game.h"


/**
 * 
 * @param atype the attacking type which will determine the attacking type.
 * @param dtype the defending mon to later determine the multiplier.
 * @brief determines the function to use depending on the users attack type.
 */
float masterte(struct move *atype, struct summon *dtype){
    switch(atype->type){
        case WATER:
            return water(dtype);
            break;
        case FIRE:
            return fire(dtype);
            break;
        case GRASS:
            return grass(dtype);
            break;
        default:
            printf("Error | Unexpected type");
    }
}

/**
 * @param dtype mon that is defending.
 * @brief When an attack is using water determines multiplyer based upon defending mon's type.
 */
float water(struct summon *dtype){
    switch(dtype->type){
        case FIRE:
            return 2;
            break;
        case GRASS:
            return .5;
            break;
        default:
            return 1;
            break;
    }
}

/**
 * @param dtype mon that is defending.
 * @brief When an attack is using water determines multiplyer based upon defending mon's type.
 */
float fire(struct summon *dtype){
    switch(dtype->type){
        case GRASS:
            return 2;
            break;
        case WATER:
            return .5;
            break;
        default:
            return 1;
            break;
    }
}

/**
 * @param dtype mon that is defending.
 * @brief When an attack is using water determines multiplyer based upon defending mon's type.
 */
float grass(struct summon *dtype){
    switch(dtype->type){
        case WATER:
            return 2;
            break;
        case FIRE:
            return .5;
            break;
        default:
            return 1;
            break;
    }
}