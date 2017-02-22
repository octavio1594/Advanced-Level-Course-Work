#ifndef PCB_CPP
#define PCB_CPP

#include"pcb.h"

using namespace std;

PCB::PCB()
{
	idPcb = 0;
	statePcb = "New";
	priorityPcb = 0;
}

PCB::~PCB()
{

}

PCB::PCB(int id, int pr, string str)
{
	idPcb = id;
	statePcb = str;
	priorityPcb = pr;
	
}

void PCB::setId(int id)
{
	idPcb = id;
}

void PCB::setPr(int pr)
{
	priorityPcb = pr;
}

void PCB::setSt(string str)
{
	statePcb = str;
}

int PCB::getID()
{
	return idPcb;
}

int PCB::getPr()
{
	return priorityPcb;
}

string PCB::getSt()
{
	return statePcb;
}

#endif
