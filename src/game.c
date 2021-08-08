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

#include "game.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include "reader.h"

// Correlation between user answer and corresponding skill by question
static const enum Game_Skill Skill_By_Answer[QUESTION_NUM][ANSWERS_NUM] =
{
    {GAME_SKILL_SCIENCE, GAME_SKILL_SPEECH, GAME_SKILL_MELEE_WEAPONS, GAME_SKILL_SNEAK},
    {GAME_SKILL_MELEE_WEAPONS, GAME_SKILL_SPEECH, GAME_SKILL_MEDICINE, GAME_SKILL_SCIENCE},
    {GAME_SKILL_SPEECH, GAME_SKILL_UNARMED, GAME_SKILL_SNEAK, GAME_SKILL_NONE},
    {GAME_SKILL_EXPLOSIVES, GAME_SKILL_BIG_GUNS, GAME_SKILL_MELEE_WEAPONS, GAME_SKILL_UNARMED},
    {GAME_SKILL_SMALL_GUNS, GAME_SKILL_BARTER, GAME_SKILL_BIG_GUNS, GAME_SKILL_EXPLOSIVES},
    {GAME_SKILL_LOCKPICK, GAME_SKILL_EXPLOSIVES, GAME_SKILL_ENERGY_WEAPONS, GAME_SKILL_REPAIR},
    {GAME_SKILL_SMALL_GUNS, GAME_SKILL_MEDICINE, GAME_SKILL_BARTER, GAME_SKILL_ENERGY_WEAPONS},
    {GAME_SKILL_BARTER, GAME_SKILL_SMALL_GUNS, GAME_SKILL_SNEAK, GAME_SKILL_MEDICINE},
    {GAME_SKILL_REPAIR, GAME_SKILL_EXPLOSIVES, GAME_SKILL_MEDICINE, GAME_SKILL_LOCKPICK},
    {GAME_SKILL_NONE, GAME_SKILL_NONE, GAME_SKILL_NONE, GAME_SKILL_NONE}
};

unsigned int ask_question(char question[QUESTION_COMP_NUM][MAX_COMP_LEN])
{
    char answer = '\0';
    bool attempt = false;

    /* Clear console */
    system("clear");

    /* Display title */
    printf("%s\n\n", question[0]);

    /* Display possible answers */
    for (unsigned int index = 1; index < QUESTION_COMP_NUM; index++)
        printf("%d - %s\n\n", index, question[index]);

    /* Get user answer */
    do
    {
        printf("(1-4) > ");

        // Read user answer
        answer = getchar();

        // Check answer validity
        if ((answer >= '1' && (answer <= '4')) && getchar() == '\n')
            attempt = true;

        // Purge standard input for next attempts/questions
        fpurge(stdin);

    } while (attempt != true);

    return ((unsigned int)(answer - '0') - 1);
}

enum Game_Skill compute_master_skill(unsigned int answer[QUESTION_NUM])
{
    // Skill counters representing user answers
    unsigned int skill_count[SKILL_NUM] = {0};
    // Counter of the most chosen skill
    unsigned int max = 0;
    // Master skill
    enum Game_Skill master_skill = GAME_SKILL_NONE;

    /* Increment skills per user answer */
    for (unsigned int index = 0; index < QUESTION_NUM; index++)
    {
        enum Game_Skill chosen_skill = Skill_By_Answer[index][answer[index]];
        if (chosen_skill != GAME_SKILL_NONE)
        {
            // Take user answer into account
            skill_count[chosen_skill]++;

            // Handle specific case of question 6, answer 2
            if (index == 5 && answer[index] == 1)
                skill_count[GAME_SKILL_BARTER]++;
        }
    }

    /* Search master skill (Most chosen skill) */
    for (unsigned int index = 0; index < SKILL_NUM; index++)
    {
        if (skill_count[index] > max)
        {
            max = skill_count[index];
            master_skill = index;
        }
    }

    return master_skill;
}

void display_result(enum Game_Skill master_skill, char job[JOB_NUM][MAX_JOB_LEN],
    char job_desc[JOB_DESC_NUM][MAX_JOB_DESC_LEN], char skill[SKILL_NUM][MAX_SKILL_LEN])
{
    /* Clear console */
    system("clear");

    /* display result */

    // Display job and skill
    printf("> %s (%s)\n\n", job[master_skill], skill[master_skill]);

    // Display job description
    printf("%s\n\n", job_desc[master_skill]);    

    return;
}

void start_game(enum Game_Lang lang)
{
    // Game resource
    FILE *resource = NULL;
    // Job array
    char job[JOB_NUM][MAX_JOB_LEN] = {0};
    // Job description array
    char job_desc[JOB_DESC_NUM][MAX_JOB_DESC_LEN] = {0};
    // Skill array
    char skill[SKILL_NUM][MAX_SKILL_LEN] = {0};
    // Question array
    char question[QUESTION_COMP_NUM][MAX_COMP_LEN] = {0};
    // User answer array
    unsigned int answer[QUESTION_NUM] = {0};
    // Master skill
    enum Game_Skill master_skill = GAME_SKILL_NONE;

    /* Select language resource */
    resource = fopen(get_lang_resource(lang), "rb");
    if (resource == NULL)
    {
        fprintf(stderr, "An error occured during language resource loading");
        exit(EXIT_FAILURE);
    }

    /* Read game assets */
    read_jobs(resource, job);
    read_jobs_description(resource, job_desc);
    read_skills(resource, skill);

    /* Start game */
    for (unsigned int index = 0; index < QUESTION_NUM; index++)
    {
        // Read question from resource
        read_question(resource, question);

        // Ask question to user and get answer
        answer[index] = ask_question(question);
    }

    /* Compute master skill and display result */
    master_skill = compute_master_skill(answer);
    display_result(master_skill, job, job_desc, skill);

    fclose(resource);

    return;
}

int main(int argc, char *argv[])
{
    enum Game_Lang lang = GAME_LANG_ENGLISH;

    /* Check consistency */
    if (argc > 2)
    {
        fprintf(stderr, "Only one language argument expected\n");
        exit(EXIT_FAILURE);
    }

    /* Check language */
    if (argc == 2)
        lang = get_game_lang(argv[1]);

    /* Start game */
    start_game(lang);

    /* Finish */
    exit(EXIT_SUCCESS);
}
