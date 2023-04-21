#include "game.h"


/**
 * 
 * @param s the string we are removing the new line from.
 * 
 * @brief removes the newline characters from a string.
 */
int nl_rm (char *s){
    for (int i = 0; s[i] != '\0'; i++){
        if (s[i] == '\n') s[i] = '\0';
    }
    return 0;
}

/**
 * 
 * @param s string we are removing the whitespace of
 * 
 * @brief replaces the whitespaces with "_"'s
 * 
 */
int ws_rp(char *s){
    for (int i = 0; s[i] != '\0'; i++){
        if (s[i] == ' ') s[i] == '_';
    }
    return 0;
}