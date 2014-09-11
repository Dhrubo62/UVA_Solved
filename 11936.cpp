/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11936 - "The Lazy Lumberjacks"
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
  int n,a,b,c;

  cin >> n;

  while(n)
    {
      cin >> a >> b >> c;

      if(a+b>c && b+c>a && c+a>b)
        printf("OK\n");
      else
        printf("Wrong!!\n");

      n--;
    }

  return 0;
}
