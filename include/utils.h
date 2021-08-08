/******************************************************************************
 * Game specifications
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

#ifndef H_UTILS
#define H_UTILS

/* Jobs */

// Number of jobs
#define JOB_NUM 13
// Maximum length for a job
#define MAX_JOB_LEN 64
// Maximum length for jobs line
#define MAX_JOBS_LINE_LEN JOB_NUM * MAX_JOB_LEN

/* Jobs description */

// Number of jobs description
#define JOB_DESC_NUM JOB_NUM
// Maximum length for a job description
#define MAX_JOB_DESC_LEN 256
// Maximum length for jobs description line
#define MAX_JOBS_DESC_LINE_LEN JOB_DESC_NUM * MAX_JOB_DESC_LEN

/* Skills */

// Number of skills
#define SKILL_NUM JOB_NUM
// Maximum length for a skill
#define MAX_SKILL_LEN 32
// Maximum length for skills line
#define MAX_SKILLS_LINE_LEN SKILL_NUM * MAX_SKILL_LEN

/* Possible skills */
enum Game_Skill
{
    GAME_SKILL_BARTER,
    GAME_SKILL_BIG_GUNS,
    GAME_SKILL_ENERGY_WEAPONS,
    GAME_SKILL_EXPLOSIVES,
    GAME_SKILL_LOCKPICK,
    GAME_SKILL_MEDICINE,
    GAME_SKILL_MELEE_WEAPONS,
    GAME_SKILL_REPAIR,
    GAME_SKILL_SCIENCE,
    GAME_SKILL_SMALL_GUNS,
    GAME_SKILL_SNEAK,
    GAME_SKILL_SPEECH,
    GAME_SKILL_UNARMED,
    GAME_SKILL_NONE // No impact
};

/* Questions */

// Number of questions
#define QUESTION_NUM 10
// Number of answers per question
#define ANSWERS_NUM 4
// Number of components for a question (1 title + 4 answers)
#define QUESTION_COMP_NUM 1 + ANSWERS_NUM
// Maximum length for a component
#define MAX_COMP_LEN 512
// Maximum length for a question line
#define MAX_QUESTION_LINE_LEN QUESTION_COMP_NUM * MAX_COMP_LEN

#endif /* H_UTILS */
