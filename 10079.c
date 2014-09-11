/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 10079
*/

# include <stdio.h>

int main(void)
{
	long int i;

	while( scanf("%ld", &i) == 1)
	{
        if(i>=0)
        {
            long int j = ((i-1)*((i-1)+1))/2;
            long int r = i+j+1;
            printf("%ld\n",r);
        }
	}

	return 0;
}
