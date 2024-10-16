#include<stdio.h>
void main()
{

int read(int[],int);
int print(int[],int);
int sort(int[],int);
int merge(int[],int,int[],int,int[]);
int a[20],n1,b[20],n2,c[40];

printf("Enter 1st limit (1-20): ");
scanf("%d",&n1);
read(a,n1);

printf("Enter 2nd limit (1-20): ");
scanf("%d",&n2);
read(b,n2);
sort(a,n1);
sort(b,n2);

printf("\nsorted 1st array\n");
print(a,n1);
printf("\nsorted 2nd array\n");
print(b,n2);

merge(a,n1,b,n2,c);
printf("\nthe merged array\n");
print(c,n1+n2);
}



// Function to read elements of an array
int read(int a[],int n)
{
int i;
printf("enter %d number:",n);
for(i=0;i<n;i++)
scanf("%d",&a[i]);
}


// Function to print elements of an array
int print(int a[],int n)
{
int i;
for(i=0;i<n;i++)
printf("%d \t",a[i]);
}

// Function to sort an array 
int sort(int a[],int n)
{
int i,j,temp;
for(i=0;i<n-1;i++)
 for(j=i+1;j<n;j++)
  if(a[i]>a[j])
  {
   temp=a[i];
   a[i]=a[j];
   a[j]=temp;
  }
}

// Function to merge two sorted arrays
int merge(int a[],int n1,int b[],int n2, int c[])
{
int i,j,k;
i=j=k=0;
while(i<n1 && j<n2)
{
  if(a[i]<b[j])
   c[k++]=a[i++];
  else
   c[k++]=b[j++];
}

while(i<n1)
   c[k++]=a[i++];
   
while(j<n2)
   c[k++]=b[j++];

}

