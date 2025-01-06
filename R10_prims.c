#include<stdio.h>
void main()
 {
  int u,v,n,i,j,ne=1;
  int visited[10]={0},min,mincost=0,cost[10][10];
  
  printf("\n Enter the number of vertices:");
  scanf("%d",&n);
  printf("\n Enter the adjacency matrix:\n");
  
    for(i=1;i<=n;i++)
    { 
      for(j=1;j<=n;j++)
       {
         scanf("%d",&cost[i][j]);
         if(cost[i][j]==0)
          {
            cost[i][j]=999;
          }
       }
    }
    
  visited[1]=1;
  printf("\n");
   while(ne<n)
    {
      min=999;
      for(i=1;i<=n;i++)
       {
         for(j=1;j<=n;j++)
         {
          if(cost[i][j]<min)        
           {
           if(visited[i]!=0 && visited[j]==0)
           {
            min=cost[i][j];
            u=i;
            v=j;
           }
          } 
         }
        }  
  printf("\nEdge %d:(%d,%d)cost:%d",ne++,u,v,min);
  mincost +=min;
  visited[v]=1;
  cost[u][v]=cost[u][v]=999;
  }
 printf("\nminimum cost=%d",mincost);
 }          
             
  

