#include <stdio.h>
#include <stdlib.h>

int uset[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, SIZE = 9;

typedef struct bit {
    unsigned char x : 1;
} bit;

// Function prototypes
void readset(bit s[], int n);
void printset(bit s[]);
void set_union(bit a[], bit b[], bit c[]);
void set_intersection(bit a[], bit b[], bit c[]);
void set_difference(bit a[], bit b[], bit c[]);


void main()  
{
    bit a[10] = {0}, b[10] = {0}, c[10] = {0};
    int n;

    printf("no.of elements for set A:");
    scanf("%d", &n);
    readset(a, n);  
    
    printf("no.of elements for set B:");
    scanf("%d", &n);
    readset(b, n);  
    
    //system("clear");
    
    printf("Set A: ");
    printset(a);
    printf("Set B: ");
    printset(b);

    set_union(a, b, c);       
    printf("Set Union: ");
    printset(c);

    set_intersection(a, b, c); 
    printf("Set Intersection: ");
    printset(c);

    set_difference(a, b, c);  
    printf("Set Difference (A-B): ");
    printset(c);
}


void printset(bit s[])
{
    int k;
    printf("{ ");
    for (k = 0; k <= SIZE; k++)  
        if (s[k].x == 1) 
            printf("%d,", uset[k]);
    printf(" }\n");
}

void readset(bit s[], int n) 
{
    int i, x, k;
    printf("enter %d elements: ",n);
    for (i = 0; i < n; i++) 
    {
        scanf("%d", &x);
        for (k = 0; k <= SIZE; k++)
            if (uset[k] == x)
            {
                s[k].x = 1;
                break;
            }
    }
}


void set_union(bit a[], bit b[], bit c[])
{
    int i;
    for(i=0; i<=SIZE; i++) 
        c[i].x = a[i].x | b[i].x;
}

void set_intersection(bit a[], bit b[], bit c[])
{
    int i;
    for(i=0; i<=SIZE; i++) 
        c[i].x = a[i].x & b[i].x;
}


void set_difference(bit a[], bit b[], bit c[])
{
    int i;
    for(i=0; i<=SIZE; ++i) 
    if (a[i].x == 1) 
        c[i].x = a[i].x ^ b[i].x; 
}
