/******************************************************************************
 * Resource reader
 ******************************************************************************
* 
 * Copyright (c) 2021, the respective contributors, as shown by the AUTHORS file.
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 * 
 *  - Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 
 *  - Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 
 *  - Neither the name of the copyright holder nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
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
