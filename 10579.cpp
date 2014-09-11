/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 10579 - "Fibonacci Numbers"
*/

# include <iostream>
# include <cstdio>
# include <cstring>
# include <string>
# include <cmath>
# include <cstdlib>
# include <algorithm>
# include <cctype>

using namespace std;

# define limit 10001

void reverse(char *p)
{
  char temp[10000];
  int i,len=strlen(p);

  for(i=0; i<len; i++)
    temp[i]=p[len-i-1];
  temp[i]='\0';

  strcpy(p,temp);
}

void add_zero(char *p, int x)
{
    int len=strlen(p);

    while(x)
    {
        p[len++]='0';
        x--;
    }

    p[len]='\0';
}

void add(char *big, char *small, char *result)
{
    char first[10000],second[10000],temp[10000];

    strcpy(first,big);  reverse(first);
    strcpy(second,small);   reverse(second);

    int len=strlen(first), carry=0,i;
    add_zero(second,len-strlen(second));

    for(i=0; i<len; i++)
    {
        carry += first[i]+second[i]-2*'0';
        temp[i] = carry%10 + '0';
        carry /= 10;
    }
    if(carry) temp[i++]=carry+'0';
    temp[i]='\0';

    reverse(temp);
    strcpy(result,temp);
}

char fibo[limit][10000];

void pre_gen_fibo(void)
{
    strcpy(fibo[1],"1");
    strcpy(fibo[2],"1");

    for(int i=3; i<limit; i++)  add(fibo[i-1],fibo[i-2],fibo[i]);
}
int main(void)
{
    pre_gen_fibo();

    int n;

    while(cin>>n)
    {
        puts(fibo[n]);
    }

	return 0;
}
