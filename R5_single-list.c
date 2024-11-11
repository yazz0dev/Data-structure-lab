#include<stdio.h>
#include<stdlib.h>

//node Defnition
struct node
{
int data;
struct node *link;
};

void main()
{
struct node *start=(struct node*)0;
struct node *insert(struct node*,int);
struct node *delete(struct node*);
void display(struct node*);
int op,data;

do
{
printf("\n- Link_list operation -\n1.insert\n2.delete\n3.display\n4.exit\n--------------\n\nYour choice: ");
scanf("%d",&op);
switch(op)
{
case 1:
printf("Enter data: ");
scanf("%d",&data);
start=insert(start,data); 
break;

case 2:
start=delete(start);
break;

case 3:
display(start);
break;

case 4:
exit(0);

default:
printf("enter a valid choice;\n"); break;
}
}while(1);

}

//insert
struct node* insert(struct node* s,int item)
{
struct node* t;
t=(struct node*)malloc(sizeof(struct node*));
t->data=item;
t->link=s;
return t;
}

//Delete
struct node* delete(struct node* s)
{
struct node* t;
t=s;
if(s!=(struct node*)0)
{
printf("%d is deleted ",t->data);
s=s->link;
free(t);
}
else
printf("The link list is empty");
return s;
}

//Display
void display(struct node*s)
{
while(s!=(struct node*)0)
{
printf("%d\t",s->data);
s=s->link;
}
}
