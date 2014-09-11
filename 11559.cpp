/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11559
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
  int cost;
  int week[10000];
} hotel[10000];

int main(void)
{
  int n,b,h,w,i,j,cost,minimum_cost,found;

  while(scanf("%d",&n)!=EOF)
    {
      cin >> b >> h >> w;

      for(i=0; i<h; i++)
        {
          cin >> hotel[i].cost;

          for(j=0; j<w; j++)
            {
              cin >> hotel[i].week[j];
            }
        }

      minimum_cost = 0;
      found = 0;

      for(i=0; i<h; i++)
        {
          for(j=0; j<w; j++)
            {
              if(hotel[i].week[j] >= n)
                {
                  found++;

                  cost = n*hotel[i].cost;

                  if(found == 1)
                    minimum_cost = cost;
                  else
                    {
                      if(cost < minimum_cost)
                        minimum_cost = cost;
                    }

                  break;
                }
            }
        }

      if(found && minimum_cost<=b)
        cout << minimum_cost << endl;
      else
        printf("stay home\n");
    }

  return 0;
}
