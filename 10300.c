/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 10300
*/

# include <stdio.h>

int main(void)
  {
	int t,T;
	scanf("%d", &T);

	for(t=0; t<T; t++)
	{
	    int n,i,total=0,a,b,c;
	    scanf("%d", &n);

	    for(i=0;i<n;i++)
	    {
	        scanf("%d %d %d",&a,&b,&c);
	        total += (a*c);
	    }

	    printf("%d\n",total);
	}

	return 0;
  }
