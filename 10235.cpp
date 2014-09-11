/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 10235 - "Simply Emirp"
*/

# include <iostream>
# include <cstdio>
# include <cstring>
# include <cmath>
# include <cstdlib>
# include <algorithm>
# include <cctype>

using namespace std;

int prime(long num)
{
  if(num<=1)
    return 0;

  if(num==2)
    return 1;

  if(!(num%2))
    return 0;

  long srt=sqrt(num*1.0);
  for(int i=3; i<=srt; i+=2)
    {
      if(!(num%i))
        return 0;
    }

  return 1;
}

void reverse(char *p)
{
  char temp[10000];
  int i,len=strlen(p);

  for(i=0; i<len; i++)
    temp[i]=p[len-i-1];
  temp[i]='\0';

  strcpy(p,temp);
}

int main(void)
{
	long num,temp;
	char str[1000000];

	while(gets(str))
	{
	    num = atol(str);
	    temp = num;

	    if(prime(num))
	    {
	        reverse(str);
	        num = atol(str);

	        if(prime(num) && num!=temp)
	        printf("%ld is emirp.\n",temp);
	        else
	        printf("%ld is prime.\n",temp);
	    }
	    else
	    printf("%ld is not prime.\n",temp);
	}

	return 0;
}
