/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11455 - "Behold My Quadrangle"
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
  int n;

  cin >> n;

  while(n)
    {
      int a,b,c,d;

      cin >> a >> b >> c >> d;

      if(a==b && b==c && c==d)
        cout << "square\n";
      else if(a==b && c==d || a==c && b==d || a==d && b==c)
        cout << "rectangle\n";
      else if((a+b+c)>d && (b+c+d)>a && (c+d+a)>b && (d+a+b)>c)
        cout << "quadrangle\n";
      else
        cout << "banana\n";

      n--;
    }

  return 0;
}
