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

#ifndef H_READER
#define H_READER

#include <stdio.h>
#include "utils.h"

/******************************************************************************
 *
 * Read jobs from a specified resource and put the result in given job array
 * 
 * NOTE: The job array is supposed to be large enough to handle all jobs
 * that would be read (See JOB_NUM and MAX_JOB_LEN)
 * 
 * NOTE: The line read is assumed to contain a list of jobs in CSV format
 * 
 * NOTE: The given resource is supposed to contain JOB_NUM jobs on one line
 *
 * Parameters
 *     resource : Resource to read
 *     job      : Result job array
 *
 * Return
 *     None
 *
 *****************************************************************************/
void read_jobs(FILE *resource, char job[JOB_NUM][MAX_JOB_LEN]);

/******************************************************************************
 *
 * Read jobs description from a specified resource and put the result in given
 * job description array
 * 
 * NOTE: The job description array is supposed to be large enough to handle
 * all jobs description that would be read (See JOB_DESC_NUM and
 * MAX_JOB_DESC_LEN)
 * 
 * NOTE: The line read is assumed to contain a list of jobs description in
 * CSV format
 * 
 * NOTE: The given resource is supposed to contain JOB_DESC_NUM jobs on one
 * line
 *
 * Parameters
 *     resource : Resource to read
 *     job_desc : Result job description array
 *
 * Return
 *     None
 *
 *****************************************************************************/
void read_jobs_description(FILE *resource, char job_desc[JOB_DESC_NUM][MAX_JOB_DESC_LEN]);

/******************************************************************************
 *
 * Read skills from a specified resource and put the result in given skill
 * array
 * 
 * NOTE: The skill array is supposed to be large enough to handle all skills
 * that would be read (See SKILL_NUM and MAX_SKILL_LEN)
 * 
 * NOTE: The line read is assumed to contain a list of skills in CSV format
 * 
 * NOTE: The given resource is supposed to contain SKILL_NUM skills on one line
 *
 * Parameters
 *     resource : Resource to read
 *     skill    : Result skill array
 *
 * Return
 *     None
 *
 *****************************************************************************/
void read_skills(FILE *resource, char skill[SKILL_NUM][MAX_SKILL_LEN]);

/******************************************************************************
 *
 * Read question from a specified resource and put the result in given question
 * array
 * 
 * NOTE: The question array is supposed to be large enough to handle all
 * question components that would be read (See QUESTION_COMP_NUM and
 * MAX_COMP_LEN)
 * 
 * NOTE: Each line of the given resource is assumed to contain a question that
 * is composed of a title and four answers in CSV format
 * 
 * NOTE: The given resource is supposed to contain QUESTION_NUM lines of
 * questions
 *
 * Parameters
 *     resource : Resource to read
 *     question : Result question array
 *
 * Return
 *     None
 *
 *****************************************************************************/
void read_question(FILE *resource, char question[QUESTION_COMP_NUM][MAX_COMP_LEN]);

#endif /* H_READER */
