/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 406 - "Prime Cuts"
*/

# include <iostream>
# include <cstdio>
# include <cstring>
# include <cmath>
# include <cstdlib>
# include <algorithm>
# include <cctype>

using namespace std;

bool prime[10000];
int list[10000],ind;

void sieve(void)
{
  list[ind++]=1;
  list[ind++]=2;

  for(long long i=3; i<10000; i+=2)
    {
      if(!prime[i])
        {
          list[ind++]=i;
          for(long long j=i*i; j<10000; j+=2*i)
            {
              prime[j]=1;
            }
        }
    }
}

int main(void)
{
  sieve();

  int c,n;

  while(cin >> c >> n)
    {
      int i,j,dur;

      for(i=0; list[i]<=c; i++);

      printf("%d %d:",c,n);

      if(i%2)
        {
          j=(i/2)-(n-1);
          dur=(i/2)-(n-1)+(2*n-1);
        }
      else
        {
          j=(i/2)-n;
          dur=(i/2)-n+(2*n);
        }

      if(j>=0 && dur<=i)
        {
          for( ; j<dur; j++)
            printf(" %d",list[j]);
        }
      else
        {
          for(j=0; j<i; j++)
            printf(" %d",list[j]);
        }

      cout << endl << endl;
    }

  return 0;
}
