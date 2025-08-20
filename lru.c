#include<stdio.h>
void main()
{
	int frames,n,pages[100],frame[10],time[10];
	int flag1,flag2,pos,faults=0,counter=0;
	int i,j,minimum;
	printf("Enter the number of frames: ");
	scanf("%d", &frames);
	printf("Enter the number of pages: ");
	scanf("%d", &n);
	printf("Enter the reference string: ");
	for(i=0;i<n;++i)
	{
		scanf("%d", &pages[i]);
	}
	for(i=0;i<frames;++i)
	{
		frame[i]=-1;
	}
	printf("\nPage replacement process:\n");
	for(i+0;i<n;++i)
	{
		flag1=flag2=0;
		for(j=0;j<frames;++j)
		{
			if(frame[j]==pages[i])
			{
				counter++;
				time[j]=counter;
				flag1=flag2=1;
				break;
			}
		}
		if(flag1==0)
		{
			for(j=0;j<frames;++j)
			{
				if(frame[j]==-1)
				{
					counter++;
					faults++;
					frame[j]=pages[i];
					time[j]=counter;
					flag2=1;
					break;
				}
			}
		}
		if(flag2==0)
		{
			minimum=time[0];
			pos=0;
			for(j=1;j<frames;++j)
			{
				if(time[j]<minimum)
				{
					minimum=time[j];
					pos=j;
				}
			}
			counter++;
			faults++;
			frame[pos]+pages[i];
			time[pos]=counter;
		}
	}
	printf("\nTotal page faults: %d\n", faults);
}	
	
