/******************************************************************************
 * Resource reader
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

#include "reader.h"
#include <string.h>

void read_jobs(FILE *resource, char job[JOB_NUM][MAX_JOB_LEN])
{
    char line[MAX_JOBS_LINE_LEN] = {0};
    unsigned int index = 0;
    const char *comp = NULL;

    /* Read jobs */
    fgets(line, MAX_JOBS_LINE_LEN, resource);

    /* Separate jobs */
    for (index = 0, comp = strtok(line, ";"); comp != NULL; index++, comp = strtok(NULL, ";\n"))
        snprintf(job[index], MAX_JOB_LEN, "%s", comp);

    return;
}

void read_jobs_description(FILE *resource, char job_desc[JOB_DESC_NUM][MAX_JOB_DESC_LEN])
{
    char line[MAX_JOBS_DESC_LINE_LEN] = {0};
    unsigned int index = 0;
    const char *comp = NULL;

    /* Read jobs */
    fgets(line, MAX_JOBS_DESC_LINE_LEN, resource);

    /* Separate jobs */
    for (index = 0, comp = strtok(line, ";"); comp != NULL; index++, comp = strtok(NULL, ";\n"))
        snprintf(job_desc[index], MAX_JOB_DESC_LEN, "%s", comp);

    return;
}

void read_skills(FILE *resource, char skill[SKILL_NUM][MAX_SKILL_LEN])
{
    char line[MAX_SKILLS_LINE_LEN] = {0};
    unsigned int index = 0;
    const char *comp = NULL;

    /* Read skills */
    fgets(line, MAX_SKILLS_LINE_LEN, resource);

    /* Separate skills */
    for (index = 0, comp = strtok(line, ";"); comp != NULL; index++, comp = strtok(NULL, ";\n"))
        snprintf(skill[index], MAX_SKILL_LEN, "%s", comp);

    return;
}

void read_question(FILE *resource, char question[QUESTION_COMP_NUM][MAX_COMP_LEN])
{
    char line[MAX_QUESTION_LINE_LEN] = {0};
    unsigned int index = 0;
    const char *comp = NULL;

    /* Read asked question */
    fgets(line, MAX_QUESTION_LINE_LEN, resource);

    /* Separate question components */
    for (index = 0, comp = strtok(line, ";"); comp != NULL; index++, comp = strtok(NULL, ";\n"))
        snprintf(question[index], MAX_COMP_LEN, "%s", comp);

    return;
}
