/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 10924 - "Prime Words"
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

void sieve(void)
{
  for(long long i=3; i<1000001; i+=2)
    {
      if(!prime[i])
        {
          for(long long j=i*i; j<1000001; j += 2*i)
            prime[j]=1;
        }
    }
}

int main(void)
{
  sieve();

  char str[1000000];

  while(gets(str))
    {
      int len=strlen(str),value=0;

      for(int i=0; i<len; i++)
        {
          if(str[i]>='a' && str[i]<='z')
            value += str[i] - 'a' + 1;
          else if(str[i]>='A' && str[i]<='Z')
            value += str[i] - 38;
        }

      if(value==2 || (value%2 && !prime[value]))
        cout << "It is a prime word.\n";
      else
        cout << "It is not a prime word.\n";
    }

  return 0;
}
