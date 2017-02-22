#ifndef PROCESS_H
#define PROCESS_H

#include <string>
using namespace std;

class process
{
	private:
  		int processID;
  		int startTime;
  		int totalCPUduration;
  		int remainingCPUduration;
  		int averageCPUburstLenght;
  		int nextCPUburstLenght;
  		int IOburstTime;
  		int priority;
  		int arrivalTime;
  		string status; // ready, running, waiting, or terminated 
  
	public:
  		process();
  		process(const process &source);
  		~process();

  		int getProcessID();
  		int getStartTime();
  		int getTotalCPUduration();
  		int getAverageCPUburstLenght();
  		int getArrivalTime();
  		void setNextCPUburstLenght(int burstLenght);
  		void setIOburstTime(int burstTime);
  		void setPriority(int priority);
  		void setStatus(string status);
		void setRemainingCPUduration(int CPUduration);
  		void displayInformation();
};
#endif // PROCESS_H
