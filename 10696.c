/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 10696
*/

# include <stdio.h>

long f(long num)
{
    if(num<=100)
    return f(f(num+11));
    else if(num>=101)
    return num-10;
}

int main(void)
  {
	long num;

	while(scanf("%ld", &num)!=EOF && num)
	{
	    printf("f91(%lu) = %lu\n",num,f(num));
	}

	return 0;
  }
