/******************************************************************************
 * Language manager
 ******************************************************************************
 * 
 * DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE 
 *                     Version 2, December 2004 
 * 
 *  Copyright (C) 2004 Sam Hocevar <sam@hocevar.net> 
 * 
 *  Everyone is permitted to copy and distribute verbatim or modified 
 *  copies of this license document, and changing it is allowed as long 
 *  as the name is changed. 
 * 
 *             DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE 
 *    TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION 
 * 
 *   0. You just DO WHAT THE FUCK YOU WANT TO.
 * 
 *****************************************************************************/

#include "lang.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

enum Game_Lang get_game_lang(const char *lang)
{
    if (strcmp("english", lang) == 0)
        return GAME_LANG_ENGLISH;
    else if (strcmp("french", lang) == 0)
        return GAME_LANG_FRENCH;
    else if (strcmp("german", lang) == 0)
        return GAME_LANG_GERMAN;

    fprintf(stderr, "Unhandled game language: %s\n", lang);
    exit(EXIT_FAILURE);
}

char *get_lang_resource(enum Game_Lang lang)
{
    switch (lang)
    {
        case GAME_LANG_ENGLISH:
            // English resource
            return "./res/english.txt";
        case GAME_LANG_FRENCH:
            // French resource
            return "./res/french.txt";
        case GAME_LANG_GERMAN:
            // German resource
            return "./res/german.txt";
        default:
            // Unhandled game language
            return "";
    }
}
