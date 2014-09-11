/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch
Problem: UVA - 10970 - "Big Chocolate"
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
  int m,n;

  while(cin >> m >> n)
    {
      cout << m-1+m*(n-1) << endl;
    }

  return 0;
}
