/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 12372
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
  int i=0,t;

  cin >> t;

  while(i<t)
    {
      int a,b,c;

      cin >> a >> b >> c;

      printf("Case %d: ",++i);

      if(a>20 || b>20 || c>20)
        printf("bad\n");
      else
        printf("good\n");
    }

  return 0;
}
