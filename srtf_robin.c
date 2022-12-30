#include<stdio.h>
#include<stdlib.h>
void srtf(int *,int *,int);
void rrb(int *,int *,int);

float avg_wt,avg_tt; //
int bt[10];//


void main()
{
//int choice,p[10],st[10];
// st service time
int choice,p[10],st[10]; // for srtf
int sp[10];  // for rrb
int i,n;

printf("Enter the number of process:");
scanf("%d",&n);
printf("Enter the burst time:");
for(i=0;i<n;i++)
{
printf("p%d",i);
scanf("%d",&bt[i]);
p[i]=i;
st[i]=bt[i];
// added extra
sp[i]=bt[i];
}

while(1)
{
printf("\n MENU\n 1.SRTF\n2.RR\n3.EXIT");
printf("Enter the choice:");
scanf("%d",&choice);
switch(choice)
{
case 1:srtf(p,bt,n);
break;
//case 2:rrb(st,bt,n);
case 2:rrb(st,sp,n);
break;
case 3:exit(0);
}

printf("\n Average waiting time is:%f",avg_wt);
printf("\n Average turn around time is:%f",avg_tt);
}

}

///////////////////////////////////////////////////////////////////////////////////////////////////////





void srtf(int p[],int bt[],int n)  // j removed tat[10] wt[10]
{
int at[10],x[10],i,small,count=0,time;
int avg[10],tt[10],a=0,t=0;
double end;
printf("Enter arrival time:");
for(i=0;i<n;i++)
{
scanf("%d",&at[i]);
}
for(i=0;i<n;i++)
{
x[i]=bt[i];
avg[i]=0;
tt[i]=0;
}

///////////////////////////////
bt[9]=9999;

for(time=0;count!=n;time++)
{


small=9;
for(i=0;i<n;i++)
{
if(at[i]<=time && bt[i]<bt[small] && bt[i]>0)
small=i;
}


bt[small]--;


if(bt[small]==0)
{
count++;
end=time+1;
tt[small]=end-at[small];
avg[small]=end-at[small]-x[small]; // weigthing time tt-burst time
t=t+tt[small];
a=a+avg[small];
}


}

printf("process no.\tburst time\t arrival time\tweighting time\ttt\n");
for(i=0;i<n;i++)
{
printf("p%d\t%d\t%d\t%d\t%d\n",p[i],x[i],at[i],avg[i],tt[i]);
}
avg_wt=(float)a/n;
avg_tt=(float)t/n;
}




///////////////////////////////////////////////////////////////////////////////////////////////////////



//void rrb(int st[],int bt[],int n) ////////////////////////////////// 10
void rrb(int st[],int sp[],int n)
{

int wt[10],tq=0,i,count=0; // swt sum of wieghting time
int swt=0, stt=0,p[20],temp;   // sq for looping
int sq=0,tt[10];             // stt sum of turn around time
printf("Enter the quantum:");
scanf("%d",&tq);

 
while(1)
{
//
for(i=0,count=0;i<n;i++)
{
temp=tq;  // time quantum
if(st[i]==0) // service time
{
count++;
continue;
}

if(st[i]>tq)
{
st[i]=st[i]-tq;
}
else if(st[i]>=0)
{
temp=st[i];
st[i]=0;
}
sq=sq+temp;
tt[i]=sq;
}

//
if(n==count)
break;
}

// while


for(i=0;i<n;i++)
{
//wt[i]=tt[i]-bt[i];
wt[i]=tt[i]-sp[i]; // weighting time=turn around time - burst time sp
swt=swt+wt[i];
stt=stt+tt[i];
p[i]=i+1; // process
}

//

avg_wt=(float)swt/n;
avg_tt=(float)stt/n;
printf("process no.\tbt\twt\ttt\n");
for(i=0;i<n;i++)
{
printf("p%d\t\t%d\t\t%d\t\t%d\n",p[i],sp[i],wt[i],tt[i]);
}
}





///////////////////////////////////////////////////////////////////////////////////////////////////////
