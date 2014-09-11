/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 900
*/

# include <iostream>
# include <cstdio>
# include <cstring>
# include <cmath>
# include <cstdlib>
# include <algorithm>
# include <cctype>

using namespace std;

long long fibonacchi(long long num)
{
  if(!num)
    return 0;
  else if (num==1 || num==2)
    return 1;
  else
    return fibonacchi(num-1) + fibonacchi(num-2);
}

int main(void)
{
  long long num;

  while (cin >> num && num)
    {
      cout << fibonacchi(num+1) << endl;
    }

  return 0;
}
