#include <stdio.h>
#define P 10
#define R 10
void main() 
{
	int processes, resources;
	printf("Enter the number of processes: ");
	scanf("%d", &processes);
	printf("Enter the number of resources: ");
	scanf("%d", &resources);
	int available[R], max[P][R], allocation[P][R], need[P][R];
	int finish[P], safeSequence[P], work[R];
	printf("Enter available resources: ");
	for (int i = 0; i < resources; i++)
	scanf("%d", &available[i]);
	printf("Enter max resource matrix:\n");
	for (int i = 0; i < processes; i++)
	for (int j = 0; j < resources; j++)
	scanf("%d", &max[i][j]);
	printf("Enter allocation matrix:\n");
	for (int i = 0; i < processes; i++)
	for (int j = 0; j < resources; j++)
	scanf("%d", &allocation[i][j]);
	printf("Enter the need matrix: \n");
	for (int i = 0; i < processes; i++)
	for (int j = 0; j < resources; j++)
	need[i][j] = max[i][j] - allocation[i][j];
	for (int i = 0; i < resources; i++)
	work[i] = available[i];
	for (int i = 0; i < processes; i++)
	finish[i] = 0;
	int count = 0;
	while (count < processes)
	{
		int found = 0;
		for (int i = 0; i < processes; i++) 
		{
		if (!finish[i])	
		{
			int j;
			for (j = 0; j < resources; j++)
			if (need[i][j] > work[j])
			break;
			if (j == resources) 
			{
				for (int k = 0; k < resources; k++)
				work[k] += allocation[i][k];
				safeSequence[count++] = i;
				finish[i] = 1;
				found = 1;
				}
				}
				}
		if (!found) 
		{
			printf("System is in an unsafe state!\n");
		}
	}
		printf("System is in a safe state.\nSafe sequence: ") ;
		for (int i = 0; i < processes; i++)
		printf("P%d ", safeSequence[i]);
		printf("\n");
}

