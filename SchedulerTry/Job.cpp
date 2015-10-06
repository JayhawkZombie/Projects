#include "stdafx.h"
#include "Job.h"


Job::Job(unsigned int JID, unsigned int PRI)
{
	JOBID = JID;
	PRIORITY = PRI;
}


Job::~Job()
{
}

