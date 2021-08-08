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

#ifndef H_LANG
#define H_LANG

/* Possible game languages */
enum Game_Lang
{
    GAME_LANG_ENGLISH, // Default
    GAME_LANG_FRENCH,
    GAME_LANG_GERMAN
};

/******************************************************************************
 *
 * Get game language according to a string.
 * If given language is unhandled, game stops
 *
 * Parameters
 *     arg_lang : String language to compare to
 *
 * Return
 *     The game language as a Game_Lang
 *
 *****************************************************************************/
enum Game_Lang get_game_lang(const char *lang);

/******************************************************************************
 *
 * Get game language resource according to selected language
 *
 * Parameters
 *     lang : Selected language
 *
 * Return
 *     Relative path of game language resource if handled language
 *     Empty string otherwise
 *
 *****************************************************************************/
char *get_lang_resource(enum Game_Lang lang);

#endif /* H_LANG */
