/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch
Problem: UVA - 11494 - "Queen"
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
  int x1,y1,x2,y2;

  while(cin >> x1 >> y1 >> x2 >> y2)
    {
      if(!x1 && !y1 && !x2 && !y2)
        break;

      int x=x1-x2, y=y1-y2;
      if(x<0) x*=-1;
      if(y<0) y*=-1;

      if(x1 == x2 && y1 == y2)
        cout << 0 << endl;
      else if(x1==x2 || y1==y2 || x == y)
        cout << 1 << endl;
      else
        cout<< 2 << endl;
    }

  return 0;
}
