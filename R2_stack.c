#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

// Stack implementation using an array
int stack[SIZE];
int sp = -1;  // Stack pointer initialization

void main()
{
    int op, data;
    void push(int);   
    int pop();      
    void display(); 

    do
    {
        printf("-----------\n1.push\n2.pop\n3.display\n4.exit\n-----------\n\nYour choice: ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("data: ");
            scanf("%d", &data);
            push(data);
            break;
        case 2:
            data = pop();
            printf("The popped item is %d \n", data);
            break;

        case 3:
            display();
            break;

        case 4:
            exit(0);

        default:
            printf("enter a valid choice;\n");
            break;
        }
    } while (1);
}

// Function to push an element onto the stack
void push(int data)
{
    if (sp == SIZE - 1) //check for stack overflow
        printf("Full stack\n");
    else
        stack[++sp] = data; 
}

// Function to pop an element from the stack
int pop()
{
    if (sp == -1)       //check for stack underflow
    {
        printf("Empty stack\n");
        exit(0);
    }
    return stack[sp--]; 
}

// Function to display the contents of the stack
void display()
{
    int tsp = sp;        
    printf("The stack Contents:\n ");
    while (tsp != -1)   
    {
        printf("%d \t", stack[tsp]);
        tsp--;
    }
    printf("\n");
}
