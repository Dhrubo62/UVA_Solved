/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 12608
*/

# include <iostream>
# include <cstdio>
# include <cstring>
# include <cmath>
# include <cstdlib>
# include <algorithm>
# include <cctype>

using namespace std;

int main(void)
{
  long long t,garbage[10000][2];

  cin >> t;

  while(t)
    {
      long long load_limit,n,i;
      int dumped_already;

      cin >> load_limit >> n;

      for(i=0; i<n; i++)
        {
          cin >> garbage[i][0] >> garbage[i][1];
        }

      long long distance=0,load=0,pickup,total,short_distance;

      dumped_already = 0;
      for(i=0; i<n; i++)
        {
          if(!i)
            short_distance = garbage[i][0];
          else
            short_distance = garbage[i][0] - garbage[i-1][0];

          distance += short_distance;

          pickup = garbage[i][1];
          total = pickup + load;

          if(total == load_limit)
            {
              load = 0;

              if(i == n-1)
                {
                  dumped_already = 1;
                  distance += garbage[i][0];
                }
              else
                {
                  distance += 2*garbage[i][0];
                }
            }
          else if(total > load_limit)
            {
              distance += 2*garbage[i][0];
              load = pickup;
            }
          else
            load += pickup;
        }

      if(!dumped_already)
        distance += garbage[n-1][0];

      cout << distance << endl;

      t--;
    }

  return 0;
}
