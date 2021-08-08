/******************************************************************************
 * Game manager
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

#ifndef H_GAME
#define H_GAME

#include <stdio.h>
#include "utils.h"
#include "lang.h"

/******************************************************************************
 *
 * Ask given question to user.
 * The question is re-asked to user until a correct answer is given (1-4)
 *
 * Parameters
 *     question : Question array
 *
 * Return
 *     User anwser (Value between 1 to 4)
 *
 *****************************************************************************/
unsigned int ask_question(char question[QUESTION_COMP_NUM][MAX_COMP_LEN]);

/******************************************************************************
 *
 * Compute the master skill according to user answers
 *
 * Parameters
 *     answer : Answer array
 *
 * Return
 *     Master skill representing user answers
 *
 *****************************************************************************/
enum Game_Skill compute_master_skill(unsigned int answer[QUESTION_NUM]);

/******************************************************************************
 *
 * Display result to user according to the master skill
 *
 * Parameters
 *     master_skill : Master skill of the user
 *     job          : Possible jobs
 *     job_desc     : Possible jobs description
 *     skill        : Possible skills
 *
 * Return
 *     None
 *
 *****************************************************************************/
void display_result(enum Game_Skill master_skill, char job[JOB_NUM][MAX_JOB_LEN],
    char job_desc[JOB_DESC_NUM][MAX_JOB_DESC_LEN], char skill[SKILL_NUM][MAX_SKILL_LEN]);

/******************************************************************************
 *
 * Start G.O.A.T game
 *
 * Parameters
 *     lang : Selected language
 *
 * Return
 *     None
 *
 *****************************************************************************/
void start_game(enum Game_Lang lang);

#endif /* H_GAME */
