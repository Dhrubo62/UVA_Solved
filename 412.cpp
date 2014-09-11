/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 412 - "Pi"
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
  int n,i,j;
  long long num[1000];

  while(cin >> n && n)
    {
      for(i=0; i<n; i++)
        cin >> num[i];

      double no_common = 0;
      double total = 0;
      for(i=0; i<n-1; i++)
        {
          for(j=i+1; j<n; j++)
            {
              total++;

              if(gcd(num[i],num[j]) == 1)
                no_common++;
            }
        }

      if(!no_common)
        {
          printf("No estimate for this data set.\n");
          continue;
        }

      double pi = pow((total/no_common)*6.0,0.5);
      printf("%0.6lf\n",pi);

    }

  return 0;
}
