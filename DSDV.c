#include <stdio.h>

int main()
{
   int n;
   int i,j,k,l;
   int a[10][10],b[10][10],visited[10][10],dest[10],seq[10][10];
   printf("\n Enter the number of nodes:");
   scanf("%d",&n);
   for(i=0;i<n;i++){
     seq[i][i] = 2*i*100;
   }
   for(i=0;i<n;i++)
   {
      for(j=0;j<n;j++)
      {
        printf("\n Enter the distance between the host %d - %d:",i+1,j+1);
        scanf("%d",&a[i][j]);
        visited[i][j] = 0;
        if(a[i][j]!=0 && i!=j){
           seq[i][j] = seq[i][i];
        }
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
   printf("Enter any node to be delted \n");
   scanf("%d",&l);
   l = l-1;
   for(i=0;i<n;i++){
     for(j=0;j<n;j++){
       if(i==l){
          a[i][j] = a[j][i] = 10000;
          if(seq[i][j]%2==0){
             seq[i][j]++;
          }
          if(seq[j][i]%2 == 0){
             seq[j][i]++;
          }
       }
     }
   }
   for(k=0;k<n;k++)
   {
      for(i=0;i<n;i++)
      {
         for(j=0;j<n;j++)
         {
            if(a[i][j]>a[i][k]+a[k][j] && seq[i][j]%2==0 && i!=l)
            {
               a[i][j]=a[i][k]+a[k][j];
               visited[i][j] = k;
               dest[i] = j;
               for(l=0;l<n;l++){
                  seq[i][l] = seq[i][l]+2;
               }
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
    
    printf("\n The output matrix:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {  if(b[i][j]!=10000){
             printf("%d\t",b[i][j]);
           }
           else{
             printf("I\t");
           }
        }
        printf("\n");
    }
    
    for(i=0;i<n;i++){
       printf("Router %d information\n",(i+1));
       for(j=0;j<n;j++){
          if(i==j && i==l){
            continue;
          }
          if(visited[i][j] != 0){
             printf("%d to %d via %d  2 hop \n\n",i+1,dest[i]+1,visited[i][j]+1);
          }       
          else{
             if(i!=j){
               printf("One Hop from %d to %d \n\n",i+1,j+1);
             }
          }
       }
    }
}
