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
