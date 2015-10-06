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


//Create Global Scheduler
SchedulerClass scheduler;


//Create HANDLER for CTRL EVENTS
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


//Just a sample task to test the scheduling
void sampleTask()
{
	std::cout << "Current Running Task: " << scheduler.getCurrentID() << std::endl;
}


//Start the timer
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
	//Create some jobs
	Job Job1(1, 0);
	Job1.funcToCall = sampleTask;
	Job Job2(2, 0);
	Job2.funcToCall = sampleTask;
	Job Job3(3, 0);
	Job3.funcToCall = sampleTask;

	//The quantum = here is 3 seconds
	unsigned int QUANTUM = 3000;

	//Add some jobs to the scheduler
	scheduler.ADDJOB(Job1);
	scheduler.ADDJOB(Job2);
	scheduler.ADDJOB(Job3);

	//BEGIN
	startTimer(schedule, QUANTUM);

	while (1);

	return 0;
}

