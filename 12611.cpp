/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch
Problem: UVA - 12611 - "Beautiful Flag"
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
  int i = 0,t;
  double radius;

  cin >> t;

  while(i<t)
    {
      cin >> radius;

      double _45 = (radius/20)*45, _55 = (radius/20)*55, _30 = (radius/20)*30;

      printf("Case %d:\n-%.0lf %.0lf\n%.0lf %.0lf\n%.0lf -%.0lf\n-%.0lf -%.0lf\n",++i,_45,_30,_55,_30,_55,_30,_45,_30);
    }

  return 0;
}
