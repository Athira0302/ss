#include <stdio.h>
void main()
{
	int n,i,bt[20], p[20], pr[20], wt[20], tat[20];
	float avg_wt=0.0, avg_tat=0.0;
	printf("enter the number of processes: ");
	scanf("%d", &n);
	for( i=0; i<n; i++)
	{
		printf("\n Process%d\n", i+1);
		printf("Burst time : ");
		scanf("%d", &bt[i]);
		printf("Priority( lower number= higher priority): ");
		scanf("%d",&pr[i]);
		p[i]=i+1;
	}
	for( i=0; i<n-1; i++)
	{
		for(int j=i+1; j<n; j++)
		{
			if(pr[i]> pr[j])
			{
				int temp= pr[i];
				pr[i] = pr[j];
				pr[j] = temp;
				 
				temp= bt[i];
				bt[i]= bt[j];
				bt[j]= temp;
				 
				temp= p[i];
				p[i]= p[j];
				p[j]= temp;
			}
		}
	}
	wt[0]=0;
	for(i=1; i<n; i++)
	{
		wt[i]=wt[i-1]+bt[i-1];
	}
	for(int i=0; i<n; i++)
	{
		tat[i]=wt[i]+bt[i];
		avg_wt+= wt[i];
		avg_tat+= tat[i];
	}
	printf("\nProcess\tBT\tP\tWT\tTAT\n");
	for(int i=0; i<n; i++)
	{
		printf("P%d\t%d\t%d\t%d\t%d\n", p[i], bt[i], pr[i], wt[i], tat[i]);
	}	
	printf("\nAverage waiting time= %2f", avg_wt/n);
	printf("\nAverage turnaround time= %2f\n", avg_tat/n);
}
