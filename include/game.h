/******************************************************************************
 * Game manager
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
 *     index    : Number of the question
 *     question : Question array
 *
 * Return
 *     User anwser (Value between 1 to 4)
 *
 *****************************************************************************/
unsigned int ask_question(unsigned int num, char question[QUESTION_COMP_NUM][MAX_COMP_LEN]);

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
