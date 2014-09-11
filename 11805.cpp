/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11805
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
  int t,n,k,p,i=0,j;

  cin >> t;

  while (i<t)
    {
      cin >> n >> k >> p;

      int cnt=0;

      for (j=k; cnt<p; )
        {
          cnt++;

          j++;

          if(j == n+1)
            j=1;
        }

      printf("Case %d: %d\n",++i,j);
    }

  return 0;
}
