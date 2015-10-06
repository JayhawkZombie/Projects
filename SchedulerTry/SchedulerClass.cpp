#include "stdafx.h"
#include "SchedulerClass.h"

#include <iostream>

void Sample() {
	std::cout << "Initial Job: " << std::endl;
}

SchedulerClass::SchedulerClass() : CurrentJob(Job(0, 0))
{
	Job initJob(0, 0);
	initJob.funcToCall = Sample;
	CurrentJob = initJob;
}


SchedulerClass::~SchedulerClass()
{
}

unsigned int SchedulerClass::getCurrentID()
{
	return ( CurrentJob.JOBID );
}

void SchedulerClass::ScheduleJobs()
{
	if (JOBQUEUE.empty())
	{
		std::cout << "Empty Job Queue..." << std::endl;
		return;
	}

	std::cout << "Beginning Job Scheduling..." << std::endl;
	std::cout << "Current Job: " << CurrentJob.JOBID << std::endl;
	std::cout << "Next Job: " << JOBQUEUE.front().JOBID << std::endl;

	Job NEXTJOB = JOBQUEUE.front();
	JOBQUEUE.pop();
	JOBQUEUE.push(CurrentJob);
	CurrentJob = NEXTJOB;

	std::cout << "=======================================" << std::endl;

	CurrentJob.funcToCall();

	return;
}

bool SchedulerClass::ADDJOB(Job JobToAdd)
{
	JOBQUEUE.push(JobToAdd);
	return true;
}
