/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11900
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
  int t,i=0,j;

  cin >> t;
  while(i<t)
    {
      int n,p,q,eggs[100];
      cin >> n >> p >> q;

      for(j=0; j<n; j++) cin>>eggs[j];

      int weight=0;
      for(j=0; j<p && j<n; )
        {
          weight += eggs[j];

          if(weight <= q) j++;
          else break;
        }
      printf("Case %d: %d\n",++i,j);
    }

  return 0;
}
