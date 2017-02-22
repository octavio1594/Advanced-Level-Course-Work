#include <iostream>
#include <sys/time.h>

using namespace std;

struct pageEntry
{ 
  bool dirty;
  bool valid;
  int pageInput;
  int last;
};

int search(struct pageEntry *Table, int totalPageFault, int fileOutput)
{  
  for(int i = 0; i < totalPageFault; i++)
    if(Table[i].pageInput == fileOutput)
      {
	return i;
      }
  return -1;
}

void simulation(int pageSize, int physicalSize, int mainInput)
{
  int elapsedTime = 0;
  int totalPageFault = physicalSize/pageSize;
  int memoryRefCount = 0; 
  int pageEntryFaults = 0;
  int Flushed = 0;
  
  if (mainInput == 1)
    {
      cout << "\nPerforming simulation using the 'Ramdom' method, please wait." << endl;
    } 
  else if(mainInput == 2)
    {
      cout << "\nPerforming simulation using the 'FIFO' algorithm, please wait." << endl;
    } 
  else
    {
      cout << "\nPerforming simulation using the 'LRU' algorithm, please wait." << endl;  
    } 
  
  struct timeval time; 
  gettimeofday(&time, NULL);  
  double t1=time.tv_sec+(time.tv_usec/500000.0);
  
  FILE *file = fopen("references.txt", "r");
  
  struct pageEntry pageTable[totalPageFault];
  for(int i = 0; i < totalPageFault; i++)
    {
      pageTable[i].dirty = false;
      pageTable[i].valid = false;
      pageTable[i].pageInput = 0;
      pageTable[i].last = 0;
    }
  
  char fileData[80];
  int lineCounter = 0;
  int fileCount = 0;
  
  while(fgets(fileData, sizeof fileData, file) != NULL)
    {
      fileCount ++;
      int fileOutput = atoi(fileData);
      
      bool dirty = fileOutput % 2;
      
      int inputFound = search(pageTable, totalPageFault, fileOutput - dirty);
      memoryRefCount ++;
       
      if(inputFound >= 0)
	{
	  pageTable[inputFound].dirty = dirty;
	  pageTable[inputFound].last = fileCount;
	  continue;
	}

      else
	{
	  pageEntryFaults ++;
	  
	  struct pageEntry insertEntry;
	  insertEntry.dirty = dirty;
	  insertEntry.valid = true;
	  insertEntry.pageInput = fileOutput - dirty;
	  insertEntry.last = fileCount;
	  int selected;
	  
	  if (mainInput == 1)
	    {
	      int random = rand() % totalPageFault;
	      selected = random;
	    }
	  
	  else if(mainInput == 2)
	    {
	      selected = lineCounter;
	      lineCounter++;
	      lineCounter = lineCounter % totalPageFault;
	    }
	 
	  else if(mainInput == 3)
	    {
	      if(!pageTable[lineCounter].valid)
		{
		  selected = lineCounter;
		  lineCounter++;
		  lineCounter = lineCounter % totalPageFault;
		}
	      else
		{
		  int lowestNumber = fileCount;
		  int lowestFound = lineCounter;
		  
		  for(int i = 0; i < totalPageFault; i++)
		    {
		      if(pageTable[i].last < lowestNumber)
			{
			  lowestFound = i;
			  lowestNumber = pageTable[i].last;
			}
		    }
		  selected = lowestFound;
		}   
	    }
	  Flushed += pageTable[selected].dirty;
	  pageTable[selected] = insertEntry;
	}
    }  
  
  gettimeofday(&time, NULL);  
  double t2=time.tv_sec+(time.tv_usec/1000000.0);  
  elapsedTime = t2-t1;
  
  if (mainInput == 1)
    {
      cout << "\nResults when using the 'Random' Method: ";
    } 
  else if(mainInput == 2)
    {
      cout << "\nResults when using the 'First In First Out' (FIFO) algorithm: ";
    } 
  else
    {
      cout << "\nResults when using the 'Least Recently Used' (LRU) algorithm: ";
    } 
  
  cout << "\nMemory reference count: " << memoryRefCount
       << "\nPage entry faults: " << pageEntryFaults
       << "\nFlushed: " << Flushed
       << "\nTime elapsed: " << elapsedTime << " seconds\n";
}

int main(int argc, char* argv[])
{
  cout << "\nAssignment 5 by Octavio Cea and Reinier Pamintuan\nCS 433, Operating Systems\nDecember 02, 2016\n";
  srand(time(NULL));
  
  int pageSize = atoi(argv[1]);
  int physicalSize = atoi(argv[2]); 
  
  if(pageSize < 256 || pageSize > 8192 || argc < 3)
    {
      cout << "\nPlease make sure your page size is a number of the power of 2\nand between 256 and 8192 bytes inclusively." << endl;
      exit(1);
    }

  if(((pageSize & (pageSize -1)) != 0) || ((physicalSize &(physicalSize - 1)) != 0))
    {
      cout << "\nPlease make sure your memory size is a number of the power of 2" << endl;
      exit(1);
    }
  
  simulation(pageSize, physicalSize, 1);
  simulation(pageSize, physicalSize, 2);
  simulation(pageSize, physicalSize, 3);
  
  return 0;
}
