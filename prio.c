#include<stdio.h>
void main()
{
	int n;
	printf("Enter the number of processes: ");
	scanf("%d", &n);
	int p[n],at[n],pr[n],wt[n],tat[n],ct[n];
	for(int i=0; i<n; i++)
	{
		p[i]= i+1;
		printf("Enter the arrival time, burst time, priority process p%d:",p[i]);
		scanf("%d%d%d", &at[i], &bt[i], &pr[i]);
	}
	for(int i=0;i<n-1; i++)
	{
		for(int j=i+1; j<n; j++)
		{
			if(at[i]>at[j]||at[i]==at[j]&&pr[i]>pr[j])
			{
				
