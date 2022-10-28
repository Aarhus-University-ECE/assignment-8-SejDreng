extern "C"{
    #include "insertion_sort.h"
    #include "linked_list.h"
    #include "list_queue.h"
}

//My function with the testcases
void test_q (queue *q, int x, int x0, int x1, int y, int y0, int y1)
{
    queue *temp = q;

    // TESTCASE 1
    init_queue(temp);
    if (empty(temp) == 1)
    {
        printf("true\n");
    }
    else
    {
        printf("false\n");
    }
    temp = q;

    // TESTCASE 2
    enqueue(temp,x); y = dequeue(temp);
    if (temp == q && x == y)
    {
        printf("true\n");
    }
    else 
    {
        printf("false\n");
    }

    //TESTCASE 3
    enqueue(temp, x0);
    enqueue(temp, x1);
    y0 = dequeue(temp); 
    y1 = dequeue(temp);

    if(temp == temp)
    {
        printf("true\n");
    }
    else
    {
        printf("false\n");
    }
    printf("%d is %d, and %d is %d\n",x0,y0,x1,y1);
}

// File for sandboxing and trying out code
int main(int argc, char **argv)
{
    // Testing my linked list 
    int testlist[] ={4,3,10,1,6};
    linked_list* test = createLinkedList();
    for (int i = 0; i < 5; ++i)
    {
        insertFront(createNode(testlist[5-i-1]), test);
    }
    
    printLL(test);
    sort(test);
    printLL(test);

    // Testing my queue
    int x = 1;
    int x0 = 2;
    int x1 = 3; 
    int y = 4;
    int y0 = 0;
    int y1 = 0;
    queue *q;

    test_q(q,x,x0,x1,y,y0,y1);
    return 0;
}

