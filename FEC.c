#include <stdio.h>
int main()
{
    int n,b,n1;
    int i,j;
    int a[20][20], r[20][20];
    printf("Enter no of data chunks to be sent:\n");
    scanf("%d",&n);
    printf("Enter no of bits to be sent in each data chunk:\n");
    scanf("%d",&b);
    printf("\nAT SENDER:\n");
    printf("Enter data chunks to be sent (in binary) :\n");
    for(i=0;i<n;i++)
        for(j=0;j<b;j++)
            scanf("%d",&a[i][j]);
    printf("Adding redundant data chunk ... !\n");
    printf("Redundant bits added\n");
    printf("Transmitting data chunks:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<b;j++)
            printf("%d ",a[i][j]);
        printf("\t");
    }
    printf("\n");
    printf("Transmitting redundant bits:\n");
    for(i=0;i<n-1;i++)
        for(j=0;j<b;j++)
            if(a[i][j] == a[i+1][j])
                a[i+1][j] = 0;
            else
                a[i+1][j] = 1;
    for(i=0;i<n;i++)
        for(j=0;j<b;j++)
            if(i==n-1)
                printf("%d ",a[i][j]);
    printf("\t");printf("\n\n \tAT RECEIVER\n\n");
    printf("Received data is:\n");
    printf("Enter the number of chunks of data received:\n");
    scanf("%d",&n1);
    if(n1!=n-1)
    {
        printf("Lost packets cannot be reconstructed\n");
        exit(0);
    }
    for(i=0;i<n1;i++)
    {
        printf("Enter bits of chunk %d:\n",i+1);
        for(j=0;j<b;j++)
            scanf("%d",&a[i][j]);
    }
    printf("\nEnter bits of redundant chunk recieved:\n");
    for(j=0;j<b;j++)
        printf("%d ",a[n-1][j]);
    printf("\n\nApplying error correction ...!\n");
    printf("Recieved data after error correction:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i<n-1)
                printf("%d ",a[i][j]);
        }
        printf("\t");
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<b;j++)
        {
            r[i][j] = a[i][j];
            a[i+1][j] = a[i+1][j]^a[i][j];
            if(i==n-1)
                printf("%d ",r[i][j]);
        }
    }
return 0;
}