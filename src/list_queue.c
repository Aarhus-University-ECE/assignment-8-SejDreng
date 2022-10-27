#include "list_queue.h"
#include <stdlib.h>

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
  qnode *second_last = malloc(sizeof(qnode));
  second_last = q->rear;
  q->rear->next = second_last;
  q->rear->data = x;
}

int dequeue(queue *q)
{
  // Add your dequeue function
  int temp = q->front->data;
  qnode *finder = malloc(sizeof(qnode));
  finder->next = q->rear;
  while(finder->next != q->front)
  {
    finder->next = finder->next->next;
    if (finder->next==finder->next->next) {
      printf("bruh");
    }
  }
  q->front = finder;
  q->front->next = NULL;

  return(temp);
}
