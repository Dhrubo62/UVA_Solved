/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 12646
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
  int a,b,c;

  while(cin >> a >> b >> c)
    {
      if((a && !b && !c)||(!a &&b && c))
        cout << "A\n";
      else if((b && !a && !c)||(!b && a && c))
        cout << "B\n";
      else if((c && !a && !b)||(!c && a && b))
        cout << "C\n";
      else
        cout << "*\n";
    }

  return 0;
}
