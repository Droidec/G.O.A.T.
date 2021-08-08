/******************************************************************************
 * Game specifications
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
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
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
