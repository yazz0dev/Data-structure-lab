#include <stdio.h>
#include <stdlib.h>
#define SIZE 10 // Maximum size of the queue

int que[SIZE]; // Queue array
int front = -1, rear = -1; // Initialize front and rear pointers

void main()
{
  // Function prototypes
  void enq(int);
  int deq();
  int search(int);
  int op, data;

  // Main loop for the queue operations
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
      data = deq();
      printf("The deleted item is %d \n", data);
      break;

    case 3:
      printf("Enter value to Search: ");
      scanf("%d", &data);

      if (search(data)) // Search for the item
      {
        printf("Item found\n");
      }
      else
      {
        printf("Item not found\n");
      }

      break;

    case 4:
      exit(0); // Exit the program

    default:
      printf("Enter a valid choice\n"); 
      break;
    }
  } while (1); 
}


// Enqueue: Adds an item to the rear of the queue
void enq(int data)
{
  if (rear == SIZE - 1) // Check for queue overflow
  {
    printf("Queue is full\n");
  }
  else
  {
    que[++rear] = data; // Increment rear and add the item
  }
}

// Dequeue: removes and returns the item from the front of the queue
int deq()
{
  if (front == rear) // Check for empty queue condition
  {
    printf("Queue is empty\n");
    exit(1); 
  }
  return que[++front]; // Increment front and return the item
}

// Search: checks if an item exists in the queue
int search(int item)
{
  if (front == rear)
  {
    return 0; // Queue is empty, so item is not found
  }

  int tfront = front + 1; // Start searching from the front position

  while (tfront != rear && que[tfront] != item)  
  {
      ++tfront;
  }
  if (que[tfront] == item)
  {
    return 1; // Item found
  }
  return 0; // Item not found
}
