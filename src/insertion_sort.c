#include "insertion_sort.h"
#include "linked_list.h"

// Creating my own switch function to switch the data-values.
void byt (node_t *x, node_t *y)
    {
        int temp = x->data;
        x->data = y->data;
        y->data = temp;
    }

void sort(linked_list *llPtr)
{
// Add your sort function here

// Creating a few pointers to keep track of the position in the linked list.
node_t *pre = llPtr->head;
node_t *cur = llPtr->head->next;
node_t *track = llPtr->head;

// The main while loop, which will sort the entire linked list.
while(cur != NULL)
{
    /*
    If the data in the two current elements is the same or already in the right order, 
    then we will move on to the next element.
    */
    if(pre->data < cur->data || pre->data == cur->data)
    {
        pre = cur;
        cur = pre->next;
        continue;
    }
    /*
    If the current element indeed is smaller than the previous one, 
    then we want to moove it until it is in the right position.
    */
    if(pre->data > cur->data)
    {
        /*
        Positioning my tracker to the desired position right before my previous element, 
        so that i can use it to move my pointers.
        */
        while (track != pre && track->next != pre)
        {
            track = track->next;
        }
        //Switching the data and mooving my pointers so they are ready to execute the sequence again.
        byt(pre,cur);
        pre = track;
        cur = pre->next;
        track = llPtr->head;
        continue;
    }
}
}
