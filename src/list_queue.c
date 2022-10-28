#include "list_queue.h"
#include <stdlib.h>
#include <stdio.h>

// Initializing my queue
void init_queue(queue *q)
{
  // Add your init_queue
  q->size = 0;
  q->front = NULL;
  q->rear = NULL;
}

// Checking if my queue is empty
int empty(queue *q)
{
  if(q->size == 0){
    return(1);
  } 
  else{
    return(0);
  }
}

// Inserting a value into my queue
void enqueue(queue *q, int x)
{
  // Making a new element with the new value
  qnode *new_objekt = malloc(sizeof(qnode));
  new_objekt->data=x;

  // If the queue is already empty
  if (q->size==0)
  {
    q->front = new_objekt;
    q->front->next = NULL;
    q->rear = new_objekt;
  }

  // If my queue has the size 1
  else if(q->size == 1)
  {
    q->rear = new_objekt;
    new_objekt->next = q->front;
  }

  // If theres already more than one object in the queue 
  else
  {
     new_objekt->next = q->rear;
     q->rear = new_objekt;
  }
  q->size++;

}

//Removing and returning the first object in the queue.
int dequeue(queue *q)
{
  //Placeholder for the value we want to return
  int temp = q->front->data;

  //if the queue size is 0, then there really isn't anythingto return
  if(q->size == 0)
  {
    printf("bruh, køen er tom.\n");
  }

  //If there is only one object in the queue, then we would like to reset the queue
  else if (q->size == 1)
  {
    q->front = NULL;
    q->rear = NULL;
  }

  //Otherwise, we remove the first object of the queue, and reasign q->front
  else
  {
    qnode *finder = malloc(sizeof(qnode));
    finder->next = q->rear;
    while(finder->next->next != q->front)
    {
      finder = finder->next;
    }
    q->front = finder->next;
  }
    q->size = q->size-1;
    
  return(temp);
}

