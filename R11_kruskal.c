#include <stdio.h>
#include <stdlib.h>
int u, v, i, j, n, ru, rv, ne = 1;
int min, mincost = 0, cost[9][9], parent[9];

int find(int u) // Added parameter u
{
    while (parent[u])
        u = parent[u];
    return u;
}

// Function to perform union of two sets
void uni(int ru, int rv) // Added parameters ru and rv
{
    parent[rv] = ru;
}


void main()
{
    printf("Enter the no.of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }

    printf("The edges of Minimum Cost Spanning Tree are\n");
    while (ne < n)
    {
        min = 999;
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (cost[i][j] < min)
                {
                    min = cost[i][j];
                    u = i;
                    v = j;
                }
            }
        }
    ru = find(u);
    rv = find(v);
    if (ru != rv)
    {
        uni(ru, rv);
        printf("%d edge (%d,%d) = %d\n", ne++, u, v, min);
        mincost += min;
    }
    cost[u][v] = cost[v][u] = 999;
}
printf("\nMinimum cost = %d\n", mincost);
}
