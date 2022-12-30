#include<stdio.h>
#include<stdlib.h>
void FIFO(int [ ],int [ ],int,int);
void lru(int [ ],int [ ],int,int);
//void opt(int [ ],int [ ],int,int);



int main()
{
int ch,YN=1,i,l,f;
int F[10],s[25];
printf("\n\n\tEnter the no of empty frames: "); 
scanf("%d",&f);
printf("\n\n\tEnter the length of the string: ");
scanf("%d",&l);


printf("\n\n\tEnter the string: ");
for(i=0;i<l;i++)
scanf("%d",&s[i]);

for(i=0;i<f;i++)
F[i]=-1;

do
{
printf("\n\n\t*********** MENU ***********");
printf("\n\n\t1:FIFO\n\n\t2:LRU \n\n\t4:EXIT"); 
printf("\n\n\tEnter your choice: "); scanf("%d",&ch);
switch(ch)
{
case 1:
for(i=0;i<f;i++)
{
F[i]=-1;
}
FIFO(s,F,l,f);
break;


case 2:
for(i=0;i<f;i++)
{
F[i]=-1;
}
lru(s,F,l,f);
break;

case 4:
exit(0);

}
printf("\n\n\tDo u want to continue IF YES PRESS 1\n\n\tIF NO PRESS 0 :"); 
scanf("%d",&YN);
}while(YN==1);

return(0);
}

//////////////////////////////////////////////////////////////////////////////////////////FIFO

void FIFO(int s[],int F[],int l,int f)
{
int i,j=0,k,flag=0,cnt=0;
printf("\n\tPAGE\t FRAMES\t FAULTS");
for(i=0;i<l;i++)
{

for(k=0;k<f;k++)
{
if(F[k]==s[i])
flag=1;
}


if(flag==0)   // page miss or page fault
{
printf("\n\t%d\t",s[i]);


F[j]=s[i]; // storing
j++;

for(k=0;k<f;k++) // print the contents of F in frame
{
printf(" %d",F[k]);
}
printf("\tPage-fault%d",cnt);
cnt++;
}

else               // page hit
{
flag=0;
printf("\n\t%d\t",s[i]);
for(k=0;k<f;k++)
{
printf(" %d",F[k]);
}
printf("\tNo page-fault");
}

if(j==f)  // if frame size is j i.e if 3 once j i.e size reaches 3 reset to 0 start point
j=0;


} // end of string

}





///////////////////////////////////////////////////////////////////////////////////////////////////




//LRU
void lru(int s[],int F[],int l,int f)
{
int i,j=0,k,m,flag=0,cnt=0,top=0;
printf("\n\tPAGE\t FRAMES\t FAULTS"); 
for(i=0;i<l;i++)   // traverse the entire string
{


for(k=0;k<f;k++)
{
if(F[k]==s[i])
{
flag=1;
break;
}
}


printf("\n\t%d\t",s[i]);


///dont match
if(j!=f && flag!=1) // 0!=3   0!=1  // page miss
{
F[top]=s[i];
j++;
if(j!=f)
top++;
}



else // **    page hit
{
///////////////////////////////////
if(flag!=1)  // lru used here 
{
for(k=0;k<top;k++)
{
F[k]=F[k+1];
}
F[top]=s[i];
}
///////////////////////////////////
if(flag==1)  // is string mathes shift and replace 
{
for(m=k;m<top;m++)
{
F[m]=F[m+1];
}
F[top]=s[i];
}

}   // **




for(k=0;k<f;k++)
{
printf(" %d",F[k]);
}

if(flag==0)
{
printf("\tPage-fault%d",cnt);
cnt++;
}
else
printf("\tNo page fault");
flag=0;


} // end of string




}
