#include <iostream>
#include "scheduler.h"
#include <vector>
#include <algorithm>

Scheduler::Scheduler()
{
        cpuState = true;
        currentTime = 0;
        quitTime = 300002;
}

Scheduler::Scheduler(int processData, int reportData)
{
        cpuState = true;
        currentTime = 0;
        quitTime = 300002;
        processInput = processData;
	reportInput = reportData;
}

Scheduler::~Scheduler(){}

void Scheduler::eventHandler(Event &e)
{
  int eventType = e.getType();
        switch(eventType)
  {
    case 1: //Whether the process arrives
      eventQueue.push(e);
      break;
    case 2: //Incase of CPU completion
      eventQueue.push(e);
      break;
    case 3: //For I/O completion
      eventQueue.push(e);
      break;
    case 4: //If the Timer Expires
      eventQueue.push(e);
break;
    default: //Otherwise give an error
      cout << "ERROR_10: Invalid event type." << endl;
      break;
        }

}

void Scheduler::run()
{
  if(cpuState)
  {


    for(int i = 0; i < processInput; i++) // adds events to the queue
    {
      process tempProcess;
      int timeTemp = tempProcess.getStartTime();
      int procIdTemp = tempProcess.getProcessID();
      Event tempEvent(timeTemp, 1, procIdTemp);
      eventHandler(tempEvent);
if(reportInput == 1)
      {
        readyQueue.push(tempProcess);
      }
      else
      {
      readyQueue.push(tempProcess);
      }
    }
  }
  else
  {

  }

  switch(reportInput) // Selector for FCFS or SJF (non Preemptive)
  {
    case 1:
    {
        cout << "You have selected First Come First Serve (FCFS):" <<endl;int tWait = 0; // Total waiting time
        int avgWait = 0; //Average waiting time
        int avgTurn = 0; //Average turn around time
        int tTurn = 0; // Total turn around time
         int min = 0;
        int sec = 0;
        int msec = 0;
      for(int i = 0; i < processInput; i++)
      {
                process tempProcess;
                tempProcess = readyQueue.front();

                int sumTurn;
                int tStart = tempProcess.getStartTime();
                int tTotalCPU = tempProcess.getTotalCPUduration();
                int tArrive = tempProcess.getArrivalTime();
                tempProcess.displayInformation();
                sumTurn = tTotalCPU + tStart - tArrive;
                tWait += tStart;
                tTurn += sumTurn;
                readyQueue.pop();
}
      avgWait = tWait/processInput; //Calculate the average wait time and conver      t the time into minutes, seconds, and milliseconds.
      min = avgWait/60000;
      sec = (avgWait%60000)/1000;
      msec = (avgWait%60000)%1000;
      cout << "\nAverage Waiting Time: " << avgWait << " milliseconds: " << endl;
      cout << "minutes: " << min << endl;
      cout << "seconds: " << sec << endl;
      cout << "milliseconds: " << msec << endl;

      avgTurn = tTurn/processInput;
      min = avgTurn/60000;
      sec = (avgTurn%60000)/1000;
      msec = (avgTurn%60000)%1000;
      cout << "\nAverage Turn Around Time: " << avgTurn << " milliseconds: " <<endl;
      cout << "minutes: " << min << endl;
      cout << "seconds: " << sec << endl;
      cout << "milliseconds: " << msec << endl;

     }
     break;
	
      case 2:
      {
      cout << "You have selected non-preemptive Shortest Job First (SJF):" <<endl;
      vector<process>sjfstack;
      vector<int>cpustack;
      int sumjob = 0;
      int tWait2 = 0;
      int avgWait2 = 0;
      int avgTurn2 = 0;
      int min2 = 0;
      int sec2 = 0;
      int msec2 = 0;
      for(int i = 0; i < processInput; i++)
      {
        process tempProcess;
        tempProcess = readyQueue.front();
        int sum;
        int tempStart = tempProcess.getStartTime();
        int tempTotalCPU = tempProcess.getTotalCPUduration();
        tempProcess.displayInformation();
        sjfstack.push_back(tempProcess);
        readyQueue.pop();
      }
        for(int j = 0; j < sjfstack.size(); j++)
        {
         cpustack.push_back(sjfstack[j].getTotalCPUduration());
        }
        sort(cpustack.begin(), cpustack.end());
        for (int n = 0; n < cpustack.size(); n++)
        {
         sumjob += cpustack[n];
         tWait2 += sumjob;
        }
      
      avgTurn2 = tWait2/processInput;
      min2 = avgTurn2/60000;
      sec2 = (avgTurn2%60000)/1000;
      msec2 = (avgTurn2%60000)%1000;
      cout << "\nAverage Turn Around Time: " << avgTurn2 << " milliseconds: " << endl;
      cout << "minutes: " << min2 << endl;
      cout << "seconds: " << sec2 << endl;
      cout << "milliseconds: " << msec2 << endl;

      tWait2 -= sumjob;
      avgWait2 = tWait2/processInput;
      min2 = avgWait2/60000;
      sec2 = (avgWait2%60000)/1000;
      msec2 = (avgWait2%60000)%1000;
      cout << "\nAverage Waiting Time: " << avgWait2 << " milliseconds: " << endl;
      cout << "minutes: " << min2 << endl;
      cout << "seconds: " << sec2 << endl;
      cout << "milliseconds: " << msec2 << endl;
      }
	break;
    
      default:
      cout << "Error_10: Invalid event type." << endl;
      break;
  }
}
