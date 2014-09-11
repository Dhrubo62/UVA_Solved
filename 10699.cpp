/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 10699 - "Count the factors"
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
int prmlst[1000001],n_cnt;

void sieve(void)
{
  prmlst[n_cnt++]=2;

  for(long long i=3; i<1000001; i+=2)
    {
      if(!prime[i])
        {
          prmlst[n_cnt++]=i;
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

  while(cin>>num && num)
    {
      long long cnt=0,root=(int)sqrt(num*1.0),i=0;

      for(i=0; prmlst[i]<=num; i++)
        {
          if(!(num%prmlst[i]))
            cnt++;
        }

      cout << num << " : " << cnt << endl;
    }

  return 0;
}
