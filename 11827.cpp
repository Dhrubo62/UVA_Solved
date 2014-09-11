/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11827 - "Maximum GCD"
*/

# include <iostream>
# include <cstdio>
# include <cstring>
# include <cmath>
# include <cstdlib>
# include <algorithm>
# include <cctype>

using namespace std;

# define IN 1
# define OUT 2

long long gcd(long a, long b)
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
  int n;
  long long num[100000];

  cin >> n;
  getchar();
  while(n)
    {
      char input[1000000];
      gets(input);
      long long len = strlen(input),i,j,number=0,cnt=0;
      int state;

      state = OUT;
      for(i=0; i<=len; i++)
        {
          if(input[i] >= '0' && input[i] <= '9')
            {
              if(state == OUT)
                state = IN;

              number = number*10 + input[i] - '0';
            }
          else if(input[i] == ' ' || i == len)
            {
              if(state == IN)
                {
                  num[cnt] = number;
                  cnt++;
                  number = 0;
                  state = OUT;
                }
            }
        }

      long long max=0,gcdd;

      for(i=0; i<cnt-1; i++)
        {
          for(j=i+1; j<cnt; j++)
            {
              gcdd = gcd(num[i],num[j]);
              if(gcdd > max)
                max = gcdd;
            }
        }

      cout << max << endl;

      n--;
    }

  return 0;
}
