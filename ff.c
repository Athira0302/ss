#include <stdio.h>
int main()
{
	int bsize[10], psize[10], bno, pno, allocation[10], i, j;
	for(i=0;i<10;i++)
	{
		allocation[i]=-1;
	}
	printf("Enter the number of blocks: ");
	scanf("%d", &bno);
	printf("Enter the size of each block: ");
	for(i=0;i<bno;i++)
	scanf("%d", &bsize[i]);
	printf("Enter the number of processes: ");
	scanf("%d", &pno);
	printf("Enter the size of each process: ");
	for(i=0;i<pno;i++)
	scanf("%d", &psize[i]);
	for(i=0;i<pno;i++)
	{
		for(j=0;j<bno;j++)
		{
			if(bsize[j]>=psize[i])
			{
				allocation[i] = j;
				bsize[j] -= psize[i];
				break;
			}
		}
	}
	printf("\nProcess No\tProcess Size\tBlock No\n");
	for (i=0;i<pno;i++)
	{
		printf("%d\t\t%d\t\t", i , psize[i]);
		if(allocation[i]!=-1)
			printf("%d\n", allocation[i] );
		else
			printf("Not allocated\n");
	}
	return 0;
}
