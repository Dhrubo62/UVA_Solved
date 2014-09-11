/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch
Problem: UVA - 113
*/

# include <stdio.h>
# include <math.h>

int main(void)
  {
	double n,p;

	while(scanf("%lf",&n)!=EOF)
	{
	    scanf("%lf",&p);
	    printf("%0.lf\n",pow(p,(1/n)));
	}

	return 0;
  }
