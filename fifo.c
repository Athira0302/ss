#include <stdio.h>
void main()
{
	int frames,pages[50],frameQueue[10],pf=0,front=0,rear=0,count=0;
	int n,i,j,found;
	printf("enter the number of pages: ");
	scanf("%d",&n);
	printf("Enter the page reference string: " );
	for(i=0;i<n;i++)
	{
		scanf("%d", &pages[i]);
	}
	printf("Enter the number of frames: ");
	scanf("%d", &frames);
	for(i=0;i<frames;i++)
	{
		frameQueue[i]=-1;
	}
	printf("\nPage\tFrames\tPage Fault\n");
	for(i=0;i<n;i++)
	{
		found=0;
		for(j=0;j<frames;j++)
		{
			if(frameQueue[j]==pages[i])
			{
				found=1;
				break;
			}
		}
		if(!found)
		{
			frameQueue[rear]=pages[i];
			rear=(rear+1)%frames;
			if(count<frames)
			count++;
			pf++;
		}
		printf("%d\t",pages[i]);
		for(j=0;j<count;j++)
		{
			printf("%d",frameQueue[j]);
		}
		if(!found)
		printf("\tYes");
		else
		printf("\tNo");
		printf("\n");
	}
	printf("\nTotal page faults=%d\n", pf);
}
		
		
	
