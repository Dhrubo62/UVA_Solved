/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 10193 - "All You Need Is Love"
*/

# include <iostream>
# include <cstdio>
# include <cstring>
# include <cmath>
# include <cstdlib>
# include <algorithm>
# include <cctype>

using namespace std;

long long gcd(long long a, long long b)
{
  if (!a)
    return b;

  if(!b)
    return a;

  long long c;

  while (1)
    {
      c = b%a;

      if (!c)
        break;

      b = a;
      a = c;
    }

  return a;
}

int main(void)
{
  long long n=0,N;

  cin >> N;
  getchar();
  while(n<N)
    {
      char input[1000000];
      long long num1=0,num2=0,i,len;
      double p;

      //inputing the first number
      gets(input);
      len = strlen(input);
      p = 0;
      for(i=len-1; i>=0; i--,p++)
        {
          if(input[i] == '1')
            num1 += (int)pow(2.0,p);
        }

      //input the second number
      gets(input);
      len = strlen(input);
      p = 0;
      for(i=len-1; i>=0 ; i--,p++)
        {
          if(input[i] == '1')
            num2 += (int)pow(2.0,p);
        }

      if(gcd(num1,num2)>1)
        printf("Pair #%lld: All you need is love!\n",++n);
      else
        printf("Pair #%lld: Love is not all you need!\n",++n);
    }

  return 0;
}
