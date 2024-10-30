#include <stdio.h>
#include <stdlib.h>
#define SIZE 5 // Maximum size of the queue

int que[SIZE];
int front = 0, rear = 0; // Initialize front and rear pointers

void main()
{
    int op, data;
    void enq(int);
    int deq();
    int search(int);

    do
    {
        printf("-----------\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Exit\n");
        printf("-----------\n\n");
        printf("Your option: ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            enq(data);
            break;
        case 2:
            if (front != rear)
            {
                data = deq();
                printf("The deleted item is %d\n", data);
            }
            else
                printf("empty circular queue\n");
            break;
        case 3:
            printf("Enter value to search: ");
            scanf("%d", &data);
            if (search(data))
                printf("Item found\n");
            else
                printf("Item not found\n");
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid option. Please try again.\n");
            break;
        }

    } while (1);
}

// Function to enqueue an element
void enq(int data)
{
    int trear = (rear + 1) % SIZE;
    if (trear == front)
    {
        printf("Queue is full\n");
    }
    else
    {
        rear = trear;
        que[rear] = data;
    }
}

// Function to dequeue an element
int deq()
{
    if (front == rear)
    {
        printf("Queue is empty\n");
    }
    else
    {
        front = (front + 1) % SIZE; // Circular increment
    }
    return que[front];
}

// Function to search for an element
int search(int item)
{
    if (front == rear)
        return 0; // Empty queue

    int tfront = (front + 1) % SIZE;
    while (tfront != rear && que[tfront] != item)
        tfront = (tfront + 1) % SIZE; // Circular increment

    if (que[tfront] == item)
        return 1; // Item found
    return 0;     // Item not found
}
