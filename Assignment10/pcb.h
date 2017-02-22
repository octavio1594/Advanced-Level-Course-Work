#ifndef PCB_H
#define PCB_H

#include<iostream>
#include<string>
using namespace std;

class PCB
{

	private:
		int idPcb;
		string statePcb;
		int priorityPcb;

	public:
		PCB();
		~PCB();
		PCB(int id, int pr, string str);

		void setId(int id);
		void setPr(int pr);
		void setSt(string str);
		int getID();
		int getPr();
		string getSt();
};

#endif
