#pragma once

#include <functional>

class Job
{
public:
	Job(unsigned int JOBID, unsigned int PRIORITY);
	~Job();

	unsigned int JOBID;
	unsigned int PRIORITY;

	std::function<void(void)> funcToCall; //NO ARGUMENTS

	void operator= (const Job J)
	{
		JOBID = J.JOBID;
		PRIORITY = J.PRIORITY;
		funcToCall = J.funcToCall;
	}

};

