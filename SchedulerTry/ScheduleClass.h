#pragma once

#include "Job.h"
#include <queue>

class SchedulerClass
{
public:
	SchedulerClass();
	~SchedulerClass();

	void ScheduleJobs();
	bool ADDJOB(Job JobToAdd);
	unsigned int getCurrentID();

	Job CurrentJob;

	std::queue<Job> JOBQUEUE;
};

