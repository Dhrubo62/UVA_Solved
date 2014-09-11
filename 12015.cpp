/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 12015
*/

# include <iostream>
# include <cstdio>
# include <cstring>
# include <cmath>
# include <cstdlib>
# include <algorithm>

using namespace std;

struct
{
  char url[1000000];
  int value;
} site[100];

int main(void)
{
  int i=0,t,j;

  cin >> t;
  while (i<t)
    {
      for (j=0; j<10; j++)
        cin >> site[j].url >> site[j].value;

      int max=site[0].value;
      for (j=1; j<10; j++)
        if (site[j].value > max)
          max = site[j].value;

      printf("Case #%d:\n",++i);

      for (j=0; j<10; j++)
        if (site[j].value == max)
          cout << site[j].url << endl;
    }

  return 0;
}
