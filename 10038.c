/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 10038
*/

# include <stdio.h>

int main(void)
  {
	int array[3010],flag[3010],n,i,dif;

	while(scanf("%d",&n)!=EOF)
	{
	    for(i=0;i<n;i++)
	    scanf("%d",&array[i]);

	    for(i=0;i<n-1;i++)
	    flag[i]=0;

	    for(i=0;i<n-1;i++)
	    {
	        dif=array[i]-array[i+1];
	        if(dif<0) dif *= -1;
	        flag[dif-1]=1;
	    }

	    int jolly=1;
	    for(i=0;i<n-1;i++)
	    if(!flag[i])
	    {
	        jolly=0;
	        break;
	    }

	    if(jolly)
	    printf("Jolly\n");
	    else
	    printf("Not jolly\n");
	}

	return 0;
  }
