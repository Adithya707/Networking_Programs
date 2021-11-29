#include <stdio.h>


int main()
{
   int n;
   int i,j,k;
   int a[10][10],b[10][10],visited[10][10],dest[10],con;
   printf("\n Enter the number of nodes:");
   scanf("%d",&n);
   for(i=0;i<n;i++)
   {
     for(j=0;j<n;j++)
     {
       printf("\n Enter the distance between the host %d - %d:",i+1,j+1);
       scanf("%d",&a[i][j]);
       visited[i][j] = 0;
     }
   }
   for(i=0;i<n;i++)
   {
     dest[i] = 0;
     for(j=0;j<n;j++)
     {
        printf("%d\t",a[i][j]);
     }
     printf("\n");
   }

   printf("Enter constraint node\n");
   scanf("%d",&con);
   con = con-1;

   for(i=0;i<n;i++)
   {
     for(j=0;j<n;j++)
     {
       if(i==con && i!=j){
         a[j][con] = 10000;
       }
     }
   }
   for(k=0;k<n;k++)
   {
     for(i=0;i<n;i++)
     {
       for(j=0;j<n;j++)
       {
         if(a[i][j]>a[i][k]+a[k][j])
         {
           a[i][j]=a[i][k]+a[k][j];
           visited[i][j] = k;
           dest[i] = j;
         }
      }
    }
  }


  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      b[i][j]=a[i][j];
      if(i==j)
      {
         b[i][j]=0;
      }
    }
  }

  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      if(i==con && i!=j){
       b[j][con] = 10000;
      }
    }
  }
  printf("\n The output matrix:\n");
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      if(b[i][j] == 10000){
         printf("I\t");
         continue;
      }
      printf("%d\t",b[i][j]);
    }
    printf("\n");
  }

  for(i=0;i<n;i++){
     for(j=0;j<n;j++){
       if(i==j && b[i][j]==10000){
         continue;
       }
       if(visited[i][j] != 0 && visited[i][j]!=con){
         printf("PATH %d => %d => %d \n",i+1,visited[i][j]+1,dest[i]+1);
       }

       else{
          if(i!=j && j!=con){
             printf("PATH %d => %d \n",i+1,j+1);
          }
       }
    }
  }
}
