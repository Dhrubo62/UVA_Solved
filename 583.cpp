/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 583 - "Prime Factors"
*/

# include <iostream>
# include <cstdio>
# include <cstring>
# include <cmath>
# include <cstdlib>
# include <algorithm>
# include <cctype>

using namespace std;

bool prime[1000001];
int prime_list[1000001],ind;

void sieve(void)
{
  prime_list[ind++]=2;

  for(long long i=3; i<1000001; i+=2)
    {
      if(!prime[i])
        {
          prime_list[ind++]=i;

          for(long long j=i*i; j<1000001; j+=2*i)
            {
              prime[j]=1;
            }
        }
    }
}

int main(void)
{
  sieve();

  long long num;

  while(cin >> num && num)
    {
      if(num<0)
        {
          num *= -1;
          printf("-%lld = -1 x",num);
        }
      else
        printf("%lld =",num);

      bool first=1;

      long long root=(long long) sqrt((double) num);

      for(long long i=0; prime_list[i]<=root; )
        {
          if(!(num%prime_list[i]))
            {
              if(first)
                first=0;
              else
                printf(" x");

              printf(" %d",prime_list[i]);
              num /= prime_list[i];
            }
          else
            i++;
        }

        if(num>1)
        {
            if(!first)
            printf(" x");

            printf(" %d",num);
        }

      cout << endl;
    }

  return 0;
}
