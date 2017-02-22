#include <iostream>
#include "process.h"
#include "random.h"

int processIDcounter = 1; 

process::process()
{

  processID = processIDcounter++;
  startTime = rand()%300002;
  totalCPUduration = 1000 + (rand()%59001);
  remainingCPUduration = totalCPUduration;
  averageCPUburstLenght = 5 + (rand()%96);
  nextCPUburstLenght = CPUBurstRandom(averageCPUburstLenght);
  IOburstTime = 30 + (rand()%71);
  priority = 0;
  arrivalTime = 0;
  status = "ready";
}

process::process(const process &source)
{
  processID = source.processID;
  startTime = source.startTime;
  totalCPUduration = source.totalCPUduration;
  remainingCPUduration = source.remainingCPUduration;
  averageCPUburstLenght = source.averageCPUburstLenght;
  nextCPUburstLenght = source.nextCPUburstLenght;
  IOburstTime = source.IOburstTime;
  priority = source.priority;
  arrivalTime = source.arrivalTime;
  status = source.status;
}

process::~process()
{
	//N/A
}

int process::getProcessID()
{
  return processID;
}

int process::getStartTime()
{
  return startTime;
}

int process::getTotalCPUduration()
{
  return totalCPUduration;
}

int process::getAverageCPUburstLenght()
{
  return averageCPUburstLenght;
}

int process::getArrivalTime()
{
  return arrivalTime;
}

void process::setNextCPUburstLenght(int burstLenght)
{
  nextCPUburstLenght = burstLenght;
}

void process::setIOburstTime(int burstTime)
{
  IOburstTime = burstTime;
}

void process::setPriority(int processPriority)
{
  priority = processPriority;
}

void process::setStatus(string processStatus)
{
  status = processStatus;
}

void process::setRemainingCPUduration(int CPUduration)
{
  remainingCPUduration = CPUduration;
}

void process::displayInformation()
{
  cout << "\nProcess ID: " << processID
  << "\nStart time: " << startTime
  << "\nTotal CPU duration: " << totalCPUduration
  << "\nRemaining CPU duration: " << remainingCPUduration
  << "\nAverage CPU burst lenght: " << averageCPUburstLenght
  << "\nNext CPU burst lenght: " << nextCPUburstLenght
  << "\nI/O burst Time: " << IOburstTime
  << "\nProcess priority: " << priority
  << "\nProcess status: " << status
  << "\nArrival time: " << arrivalTime << endl;
}
