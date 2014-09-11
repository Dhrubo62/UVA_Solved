/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 10346
*/

# include <stdio.h>

int main(void)
  {
	int n,k,butt;

	while(scanf("%d %d",&n,&k)!=EOF)
	{
	    if(k>1)
	    {
	        butt=n;
	        while(butt>=k)
	        {
	            n += (butt/k);
	            butt=(butt/k)+(butt%k);
	        }
	    }
	    printf("%d\n",n);
	}

	return 0;
  }
