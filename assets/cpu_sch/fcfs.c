#include<stdio.h>
int  at[20],bt[20];
int waitingtime( int n,
int burst_time[], int wait_time[]) {
   // waiting time for first process is 0
   wait_time[0] = 0;
   // calculating waiting time
   for (int i = 1; i < n ; i++ )
   wait_time[i] = burst_time[i-1] + wait_time[i-1] ;
   return 0;
}
int turnaroundtime( int proc[], int n,
int burst_time[], int wait_time[], int tat[]) {
   // calculating turnaround time by adding
   // burst_time[i] + wait_time[i]
   int i;
   for ( i = 0; i < n ; i++)
   tat[i] = burst_time[i] + wait_time[i];
   return 0;
}

void avgtime(int at[],int n,int bt[])
{
	int wt[n],tat[n],total_wt=0,total_tat=0;
	waitingtime(n,bt,wt);
	turnaroundtime(at,n,bt,wt,tat);
	printf("process \t brusttime\t waiting time\t turn around time \n");
	for (int i=0;i<n;i++)
	{
		total_wt=total_wt+wt[i];
		total_tat=total_tat+tat[i];
		printf("at[%d] \t %d \t   \t %d  \t %d \n",(i+1),bt[i],wt[i],tat[i]);
	}
	int s=(float)total_wt / (float)n;
	int t=(float)total_tat/(float)n;
	printf("\n Total time around time: %d",total_tat);
	printf(" \n average turn around time : %d", t);
	printf("\n total waiting time %d ",total_wt);
	printf("\n average waiting time %d ",s);
}
int main()
{
	int i,n;
	printf("enter the number of process \n");
	scanf("%d",&n);
	printf("enter burst time \n");
	for (i=0;i<n;i++)
	{
		scanf("%d",&bt[i]);
	}
	avgtime(at,n,bt);
	return 0;
}
