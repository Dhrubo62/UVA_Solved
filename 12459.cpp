/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 12459 - "Bees' ancestors"
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
  long long num,fibo[100],i;

  for(i=0; i<90; i++)
    {
      if(!i)
        fibo[i] = 1;
      else if(i == 1)
        fibo[i] = 2;
      else
        fibo[i] = fibo[i-1] + fibo[i-2];
    }

  while(cin >> num && num)
    {
      cout << fibo[num-1] << endl;
    }

  return 0;
}
