/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11636 - "Hello World!"
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
  double num, i;
  int case_number=0;

  while(cin>>num && num>=0)
    {
      if(!num || num==1)
        {
          printf("Case %d: 0\n",++case_number);
          continue;
        }

      i = 1.0;
      while(1)
        {
          if(pow(2.0,i)>=num)
            break;
          else
            i++;
        }

      printf("Case %d: %.0lf\n",++case_number,i);
    }

  return 0;
}
