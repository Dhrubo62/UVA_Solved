/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch
Problem: UVA - 661 - "Blowing the fuses"
*/

# include <iostream>
# include <cstdio>
# include <cstring>
# include <cmath>
# include <cstdlib>
# include <algorithm>
# include <cctype>

using namespace std;

struct
{
  int state;
  int pow;
} device[100];

int main(void)
{
  int n,m,c,operation[1000000],total_pow,max_pow,blown,s=0;

  while(cin >> n >> m >> c && n && m && c)
    {
      int i;

      for(i=0; i<n; i++)
        {
          device[i].state = 0;
          cin >> device[i].pow;
        }

      total_pow = 0;
      max_pow = 0;
      blown = 0;

      for(i=0; i<m; i++)
        cin >> operation[i];

      for(i=0; i<m; i++)
        {

          if(!device[operation[i]-1].state)
            {
              device[operation[i]-1].state = 1;
              total_pow += device[operation[i]-1].pow;

              if(total_pow > c)
                {
                  blown = 1;
                  break;
                }
              else
                {
                  if(total_pow > max_pow)
                    max_pow = total_pow;
                }
            }
          else
            {
              device[operation[i]-1].state = 0;
              total_pow -= device[operation[i]-1].pow;
            }
        }

      printf("Sequence %d\n",++s);

      if(blown)
        printf("Fuse was blown.\n\n");
      else
        printf("Fuse was not blown.\nMaximal power consumption was %d amperes.\n\n",max_pow);
    }

  return 0;
}
