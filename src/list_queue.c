#include "list_queue.h"
#include <stdlib.h>
#include <stdio.h>

void init_queue(queue *q)
{
  // Add your init_queue
  q->size = 0;
  q->front = NULL;
  q->rear = NULL;
}

int empty(queue *q)
{
  if(q->size == 0){
    return(1);
  } 
  else{
    return(0);
  }
}

void enqueue(queue *q, int x)
{
  qnode *new_objekt = malloc(sizeof(qnode));
  new_objekt->data=x;

  if (q->size==0)
  {
    q->front = new_objekt;
    q->front->next = NULL;
    q->rear = new_objekt;
  }
  else if(q->size == 1)
  {
    q->rear = new_objekt;
    new_objekt->next = q->front;
  }
  else
  {
     new_objekt->next = q->rear;
     q->rear = new_objekt;
  }
  q->size++;

}

int dequeue(queue *q)
{
  int temp = q->front->data;
  if(q->size == 0)
  {
    printf("bruh, køen er tom.\n");
  }
  else if (q->size == 1)
  {
    q->front = NULL;
    q->rear = NULL;
  }
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

