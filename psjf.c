//Shortest Job First Scheduling Algorithm 
#include<stdio.h>
void main()
{
int i,n,p[10]={1,2,3,4,5,6,7,8,9,10},min,k=1,btime=0;
int bt[10],temp,j,at[10],wt[10],tt[10],ta[10],sum=0;
float wavg=0,tavg=0,tsum=0,wsum=0;
printf("Shortest Job First Scheduling");
printf("\nEnter the No. of processes :");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("\tEnter the burst time :");
scanf(" %d",&bt[i]);
printf("\tEnter the arrival time :");
scanf(" %d",&at[i]);
}
/*Sorting According to Arrival Time*/
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
if(at[i]<at[j])
{
temp=p[j];
p[j]=p[i];
p[i]=temp;
temp=at[j];
at[j]=at[i];
at[i]=temp;
temp=bt[j];
bt[j]=bt[i];
bt[i]=temp;
}
}
}
for(j=0;j<n;j++)
{
btime=btime+bt[j];
min=bt[k];
for(i=k;i<n;i++)
{
if(btime>=at[i] && bt[i]<min)
{
temp=p[k];
p[k]=p[i];
p[i]=temp;
temp=at[k];
at[k]=at[i];
at[i]=temp;
temp=bt[k];
bt[k]=bt[i];
bt[i]=temp;
}
}
k++;
}
wt[0]=0;
for(i=1;i<n;i++)
{
sum=sum+bt[i-1];
wt[i]=sum-at[i];
wsum=wsum+wt[i];
}
wavg=(wsum/n);
ta[0]=bt[0];
for(i=0;i<n;i++)
{
ta[i+1]=ta[i]+bt[i+1];
tt[i]=ta[i]-at[i];
tsum=tsum+tt[i];
}
tavg=(tsum/n);
printf("\n RESULT:-");
printf("\n P\t B\t A\t C\t W\t TA" );
for(i=0;i<n;i++)
{
printf("\n p%d\t %d\t %d\t %d\t %d\t %d",p[i],bt[i],at[i],ta[i],wt[i],tt[i]);
}
printf("\n\nAVERAGE WAITING TIME : %f",wavg);
printf("\nAVERAGE TURN AROUND TIME : %f",tavg);
}