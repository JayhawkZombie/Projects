// Scheduler.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <chrono>
#include <iostream>
#include <string>
#include <Windows.h>
#include <thread>
#include <functional>
#include <queue>
#include <stdio.h>

#include "Job.h"
#include "SchedulerClass.h"

BOOL CtrlHandler(DWORD fdwCtrolType)
{
	switch (fdwCtrolType)
	{
	case CTRL_C_EVENT:
		printf("\n\n\nCTRL_C_EVENT\n\n\n");
		//Beep(750, 300);
		return(TRUE);
	}
}


SchedulerClass scheduler;

void sampleTask()
{
	std::cout << "Current Running Task: " << scheduler.getCurrentID() << std::endl;
}

void startTimer(std::function<void(void)> func, unsigned int interval)
{
	std::thread([func, interval]()
	{
		while (1)
		{
			func();
			std::this_thread::sleep_for(std::chrono::milliseconds(interval));
		}
	}).detach();
}



void schedule()
{

	scheduler.ScheduleJobs();

}


int _tmain(int argc, _TCHAR* argv[])
{

	Job Job1(1, 0);
	Job1.funcToCall = sampleTask;
	Job Job2(2, 0);
	Job2.funcToCall = sampleTask;
	Job Job3(3, 0);
	Job3.funcToCall = sampleTask;


	unsigned int QUANTUM = 3000;


	scheduler.ADDJOB(Job1);
	scheduler.ADDJOB(Job2);
	scheduler.ADDJOB(Job3);

	startTimer(schedule, QUANTUM);

	while (1);

	return 0;
}

