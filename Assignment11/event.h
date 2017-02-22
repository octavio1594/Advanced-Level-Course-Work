#ifndef EVENT_H
#define EVENT_H

#include<iostream>
using namespace std;

class Event
{
private:
  int time;  //time when event should take place
  int type;  //type of event
  int procId;  //process to which event belongs

public:
  Event();
  Event(int timeInput, int typeInput, int procIdInput);
  ~Event();
  Event(const Event &cSource);

  void setTime(int input);
  void setType(int input);
  int getType();
  void displayInfo();
};
#endif // EVENT_H
