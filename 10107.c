/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 10107
*/

# include <stdio.h>
# include <stdlib.h>

int compare(int *a,int *b)
{
    return *a>*b;
}

int main(void)
  {
	long long array[30000];
	int i,n=0;
    while(scanf("%lld",&array[n])!=EOF)
    {
        n++;
        qsort(array,n,sizeof(long long),compare);

        long long median;
        if(n%2)
        median=array[((n+1)/2)-1];
        else
        median=(array[n/2]+array[(n/2)-1])/2;

        printf("%lld\n",median);
    }

	return 0;
  }
