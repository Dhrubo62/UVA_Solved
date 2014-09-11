/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 10509
*/

# include <iostream>
# include <cstdio>
# include <cstring>
# include <cmath>
# include <cstdlib>
# include <algorithm>
# include <cctype>

using namespace std;

double nearesst_cuberoot(double num)
{
  double i=1;
  while(1)
    {
      if(i*i*i > num)
        break;
      else
        i++;
    }

  i--;
  return i;
}

int main(void)
{
  double n;

  while(cin >> n && n)
    {
      double a,dx;

      a = nearesst_cuberoot(n);

      dx = (n-a*a*a)/(3*a*a);

      printf("%0.4lf\n",a+dx);
    }

  return 0;
}
