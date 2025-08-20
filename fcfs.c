#include<stdio.h>
void main()
{
	int pid[10], bt[10], n;
	printf("Enter the number of process: ");
	scanf("%d", &n);
	printf("Enter the process id of all the processes:");
	for(int i=0; i<n; i++)
	{
		scanf("%d", &pid[i]);
	}
	printf("Enter the burst time of all the processes: ");
	for(int i=0; i<n; i++)
	{
		scanf("%d",&bt[i]);
	}
	int i, wt[n];
	wt[0]=0;
	for(i=1; i<n; i++)
	{	
		wt[i]=bt[i-1]+wt[i-1];
	}
	printf("Process ID       Burst time      Waiting time      Turnaround time\n");
	float twt=0.0, ttat=0.0;
	for(i=0; i<n; i++)
	{
		printf("%d\t\t", pid[i]);	
		printf("%d\t\t", bt[i]);
		printf("%d\t\t", wt[i]);
		printf("%d\t\t", bt[i]+wt[i]);
		printf("\n");
		twt += wt[i];
		ttat += (bt[i]+wt[i]);
	}
	float awt,atat;
	awt= twt/n;
	atat= ttat/n;
	printf("Averge waiting time= %f\n", awt);
	printf("Average turnaround time= %f",atat);
}
		
