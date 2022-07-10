#include<stdio.h> //include header file
#include<stdlib.h>
int main()
{
static
int
alloc[10][10],max[10][10],need[10][10],flag=0,available[20],finish[10],work[10],
sequence[10],m,n,count,i,j,k,num;
printf("Enter the total no. of processes:");
scanf("%d",&n);
printf("Enter the total no. of resource types:");
scanf("%d",&m);
printf("Enter allocation matrix:");
for(i=0;i<n;i++)
{
printf("\nprocess%d:",i+1);
for(j=0;j<m;j++)
scanf("%d",&alloc[i][j]);
}
printf("\n\nEnter maximum matrix:");
for(i=0;i<n;i++)
{
printf("\nfor process%d:",i+1);
for(j=0;j<m;j++)
scanf("%d",&max[i][j]);
}
printf("\n\nEnter available instances:");
for(i=0;i<m;i++)
scanf("%d",&available[i]);
printf("\n\nAllocation\n");
for(i=0;i<n;i++)
{
for(j=0;j<m;j++)
printf("%d\t",alloc[i][j]);
printf("\n");
}
printf("Maximum\n");
for(i=0;i<n;i++)
{
for(j=0;j<m;j++)
printf("%d\t",max[i][j]);
printf("\n");
}
printf("Available\n");
for(j=0;j<m;j++)
printf("%d\t",available[j]);
for(i=0;i<n;i++)
for(j=0;j<m;j++)
need[i][j]=max[i][j]-alloc[i][j];
printf("\n need\n");
for(i=0;i<n;i++)
{
for(j=0;j<m;j++)
printf("%d\t",need[i][j]);
printf("\n");
}
for(i=0;i<n;i++)
finish[i]=0;
for(j=0;j<m;j++)
work[j]=available[j];
k=0;
while(k<n)
{
flag=0;
for(i=0;i<n;i++)
{
if(finish[i]==0)
{
for(j=0;j<m;j++)
{
if(need[i][j]>work[j])
break;
}
if(j==m)
{
for(j=0;j<m;j++)
work[j]=work[j]+alloc[i][j];
finish[i]=1;
sequence[k++]=i;
flag=1;
}
}
}
if(flag==0)
{
printf("The system is in unsafe state!!!\n");
exit(0);
}
}
printf("\n The System is in safe state!!\n Safe Sequence:");
for(i=0;i<n-1;i++)
{
printf("P%d->",sequence[i]);
}
printf("P%d\n",sequence[n-1]);
}
