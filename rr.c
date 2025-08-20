#include<stdio.h>
void avgtimes(int wt[],int tat[],int n)
{
	int i;
	float total_wt=0,total_tat=0;
	for(i=0;i<n;i++)
	{
		total_wt = total_wt + wt[i];
		total_tat = total_tat + tat[i];
	}
	printf("average wt : %f\n",total_wt/n);
	printf("average tat : %f\n",total_tat/n);
}		
int main()
{
	int j,i,n,wt[10],bt[10],tat[10],p[10],at[10],remain_bt[10],quantum,ct=0,completed=0;
	printf("Enter the number of processes : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("p %d\n",i+1);
		printf("Enter the arrival time: ");
		scanf("%d",&at[i]);
	 	printf("Enter the burst time: ");
		scanf("%d",&bt[i]);
		remain_bt[i]=bt[i];	
	}
	printf("Enter the time quantum for the process : ");
	scanf("%d",&quantum);
	while(completed<n)
	{
		for(i=0;i<n;i++)
		{
			if((at[i]<=ct)&&(remain_bt[i]>0))
			{
				if(remain_bt[i]<=quantum)
				{
					ct+=remain_bt[i];
					tat[i]=ct-at[i];
					wt[i]=tat[i]-bt[i];
					remain_bt[i]=0;
					completed++;
				}
				else
				{
					remain_bt[i]-=quantum;
					ct+=quantum;
				}
			}
		}
	}					
	printf("PROCESS\t\tAT\t\tBT\t\tWT\t\tTAT\n");
	for(i=0;i<n;i++)
	{
		printf("p%d\t\t%d\t\t%d\t\t%d\t\t%d",i+1,at[i],bt[i],wt[i],tat[i]);
		printf("\n");
	}
	avgtimes(wt,tat,n);
}				
