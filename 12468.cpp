/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 12468
*/

# include <iostream>
# include <cstdio>
# include <cstring>
# include <cmath>
# include <cstdlib>
# include <algorithm>

using namespace std;

int main(void)
{
  int a,b,res;

  while(cin >> a >> b && !(a==-1 && b==-1))
    {
      res = b - a;

      if(res<0)
        res*=-1;

      if(res>50)
        res = 100 - res;

      cout << res << endl;
    }

  return 0;
}
