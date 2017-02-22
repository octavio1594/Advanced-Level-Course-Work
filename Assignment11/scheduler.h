#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <queue>
#include "event.h"
#include "process.h"

using namespace std;

class Scheduler
{
private:
  bool cpuState; // is the CPU idle?
  int currentTime;
  int quitTime;
  int processInput;
  int reportInput;
 queue<process> readyQueue;

 queue<Event> eventQueue;

public:
  Scheduler();
  Scheduler(int processData, int reportData);
  ~Scheduler();

  void eventHandler(Event &e);
  void run();
};
#endif // SCHEDULER_H


