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
  qnode *second_last = malloc(sizeof(qnode));
  if(empty(q)==0){
    second_last = q->rear;
    q->rear->next = second_last;
    q->rear->data = x;
  }
  else
  {
    second_last->data = x;
    second_last->next = NULL;
    q->front = second_last;
    q->rear = second_last;
  }
  q->size++;
}

int dequeue(queue *q)
{
  /*
  // Add your dequeue function
  if(empty(q) == 0){
  int temp = q->front->data;
  qnode *finder = malloc(sizeof(qnode));
  finder->next = q->rear;
  while(finder->next != q->front)
  {
    finder->next = finder->next->next;
  }
  q->front = finder;
  q->front->next = NULL;
  q->size = q->size - 1;
  }
  else
  printf("dude, is empty");



  return ();*/

  if (empty(q)==1) {
    return 0;
  }

  int return_value = q->front->data;

  qnode *finder = malloc(sizeof(qnode));
  finder = q->rear;
  while (finder->next != q->front) {
    finder->next=finder->next->next;
  }

  if (q->size == 1){
    q->size=0;
    q->front=NULL;
    q->rear=NULL;
    return return_value;
  } else {
    q->front=finder;
    q->front->next=NULL;
    q->size-=1;
    return return_value;
  }



}
