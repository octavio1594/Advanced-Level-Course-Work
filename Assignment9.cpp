/*
Octavio Cea, Reinier Pamintuan
11/17/16
Operating Systems CS 433
Assignment 4, Producer-Consumer Problem
*/

#include<pthread.h>
#include<semaphore.h>
#include<string.h>
#include<time.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

const int SIZE = 5; 
int buffer[SIZE];
int count, first, last;
pthread_mutex_t mutex;
sem_t max;
sem_t none;

int insert(int item)
{
  if(count != SIZE)
  {
    buffer[last] = item;
    printf ("\nProducer: %d", item);
    last = (last + 1) % SIZE;
    count++;

    return 0;
  }
     
  return -1;
}

int remove(int *item)
{
  if(count > 0)
  {
    item = &buffer[first];
    printf("\nConsumer: %d", buffer[first]);
    first = (first + 1) % SIZE;
    count--;
    
    return 0;
  }
  
  return -1;
}

void print()
{
  if(count == 0)
  {
    printf("\nThere is nothing in the buffer.");
  }

  else
  {
    printf("\nThe updated buffer is [");

    if(last > first)
    {
      for(int i = first; i < last; i++)
      {
        printf(" %i ", buffer[i]);
      }
    }

    if(last <= first)
    {
      for(int i = first; i < SIZE; i++)
      {
        printf(" %i ", buffer[i]);
      }
      for(int i = 0; i < last; i++)
      {
        printf(" %i ", buffer[i]);
      }
    }

    printf("].\n");
  }
}

void *producer(void *parameter)
{
  int item;

  while(1)
  {
    sleep(rand() % 5 + 1);
    item =  rand() % 50 + 1;
    sem_wait(&none);
    pthread_mutex_lock(&mutex);

    if(insert(item) == 0)
      print();
    
    pthread_mutex_unlock(&mutex);
    sem_post(&max); 
  }
}

void *consumer(void *parameter)
{
  int item;
  
  while(1)
  {
    sleep(rand() % 5 + 1);
    sem_wait(&max);
    pthread_mutex_lock(&mutex);

    if(remove(&item) == 0)
      print();
    
    pthread_mutex_unlock(&mutex);
    sem_post(&none);
  }
}

int main(int argc, char *argv[]) 
{
  printf("\nProducer Consumer Problem, Assignment 04\nby Octavio Cea and Reinier Pamintuan\nOperating Systems, CS433\nNovember 17, 2016");

  srand(time(NULL));
  
  int sleepInput = atoi(argv[1]);
  int producerInput = atoi(argv[2]);
  int consumerInput = atoi(argv[3]);

  if((argc < 4) || (sleepInput <= 0) || (producerInput <= 0) || (consumerInput <= 0))  
  {
    printf("\nError; Please enter values that are greater than 0.");
    return -1;
  }
  
  char *produce = "Producer";
  char *consume = "Consumer";
  pthread_t producerThread[producerInput];
  pthread_t consumerThread[consumerInput];  
  sem_init(&none, 0, SIZE);
  sem_init(&max, 0, 0);
  pthread_mutex_init(&mutex, NULL); 
  
  for(int i = 0; i < producerInput; i++)
  {
    pthread_create(&producerThread[i], NULL, producer, produce);
  }
 
  for(int i = 0; i < consumerInput; i++)
  {
    pthread_create(&consumerThread[i], NULL, consumer, consume);
  }

  sleep(sleepInput);

  return 0;
}
