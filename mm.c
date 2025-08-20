#include<stdio.h>
#define MAX 10
int main()
{
	int blockSize[MAX],processSize[MAX],allocation[MAX];
	int i,j,blocks,process,choice;
	int orginalBlockSize[MAX];
	printf("Enter the number of memory blocks: ");
	scanf("%d",&blocks);
	printf("Enter sizes of %d blocks:\n",blocks);
	for(i=0;i<blocks;i++)
	{
		scanf("%d",&processSize[i]);
		orginalBlockSize[i]=blockSize[i];
	}
	printf("Enter the number of processes");
	scanf("%d",&process);
	printf("Enter the size of %d processes",process);
	for(i=0;i<process;i++)
	{
		scanf("%d",&processSize[i]);
	}
	do
	{
		for(i=0;i<blocks;i++)
		{
			blockSize[i]=orginalBlockSize[i];
		}
		for(i=0;i<process;i++)
		{
			allocation[i]=-1;
		}
		printf("\n1.First Fit\n2.BestFit\n3.Worst Fit\n4.Exit\nEnter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			for(i=0;i<process;i++)
			{
				for(j=0;j<blocks;j++)
				{
					if(blockSize[j]>=processSize[i])
					{
						allocation[i]=j;
						blockSize[j]-=processSize[i];
						break;
					}
				}
			}
			break;
			case 2:
			for(i=0;i<process;i++)
			{
				int best=-1;
				for(j=0;j<blocks;j++)
				{	
					if(blockSize[j]>=processSize[i])
					{
						if(best==-1||blockSize[j]<blockSize[best])
						best=j;
					}
				}
					if(best!=-1)
					{
						allocation[i]=best;
						blockSize[best]-=processSize[i];
					}
			}
			break;
			case 3:
			for(i=0;i<process;i++)
			{
				int worst=-1;
				for(j=0;j<blocks;j++)
				{	
					if(blockSize[j]>=processSize[i])
					{
						if(worst==-1||blockSize[j]>blockSize[worst])
						worst=j;
					}
				}
					if(worst!=-1)
					{
						allocation[i]=worst;
						blockSize[worst]-=processSize[i];
					}
			}
			break;
			case 4:
			printf("Exiting...\n");
			break;
			default:
			printf("Invalid choice\n");
			
		}	
		if(choice >= 1 && choice <= 3)
		{
			printf("\nProcess no\tProcess Size\tBlock Number\n");
			for(i=0;i<process;i++)
			{
				printf("%d\t\t%d\t\t",i+1,processSize[i]);
				if(allocation[i]!=-1)
				printf("%d\n",allocation[i]+1);
				else
				printf("Not allocated \n");
			}
		}
	}while(choice!=4);
	return 0;
}	
			
					
					
					
			
