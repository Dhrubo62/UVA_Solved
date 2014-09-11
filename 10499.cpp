/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 10499 - "The land of justice"
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
  long long num;

  while(cin >> num && num >= 0)
    {
      if(!num || num == 1)
        printf("0%%\n");
      else
        printf("%lld%%\n",num*25);
    }

  return 0;
}
