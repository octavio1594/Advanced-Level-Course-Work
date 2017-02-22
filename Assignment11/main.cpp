#include <time.h>
#include "scheduler.h"

using namespace std;

int main()
{
  	cout << "\nAssignment 03 by Octavio Cea and Reinier Pamintuan, CS 433 Operating systems";
  	srand(time(NULL));
  	int numOfProcesses;
  	int schedulerType;
    
  	cout << "\nPlease enter the number of processes that you would you like to simulate: ";
  	cin >> numOfProcesses;
  	cout << "\n1) First Come First Serve (FCFS)\n2) Non-preemptive Shortest Job First (SJF)					\nPlease select a scheduling algorithm: ";
  	cin >> schedulerType;

  	Scheduler simulation(numOfProcesses, schedulerType);
  	simulation.run();
  
 	return 0;
}
