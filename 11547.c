/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11547
*/

# include <stdio.h>

int main(void)
  {
	long long num;
	int t;
	scanf("%d",&t);
	while(t)
	{
	    scanf("%lld",&num);

	    num=((((num*63)+7492)*5)-498);

	    if(num<0)
	    num*=-1;

	    num%=100;
	    num/=10;
	    printf("%lld\n",num);

	    t--;
	}

	return 0;
  }
