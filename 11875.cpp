/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11875
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
  int t,i=0;

  cin >> t;
  while(i<t)
    {
      int n,array[100];

      cin >> n;

      for(int j=0; j<n; j++)
        cin >> array[j];

      sort(array,array+n);

      printf("Case %d: %d\n",++i,array[n/2]);
    }

  return 0;
}
