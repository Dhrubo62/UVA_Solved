/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 10922 - "2 the 9s"
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
  char num[1000000];

  while(gets(num))
    {
      if(num[0] == '0')
        break;

      int s=0, i;
      for(i=0; num[i]; i++)
        {
          s += (num[i] - '0');
        }

      if(s%9)
        {
          printf("%s is not a multiple of 9.\n",num);
          continue;
        }

      int degree = 1;
      while(s != 9 && s > 9)
        {
          int temp = s;
          s = 0;

          while(temp)
            {
              s += temp%10;

              temp /= 10;
            }

          degree++;
        }

      printf("%s is a multiple of 9 and has 9-degree %d.\n",num,degree);
    }

  return 0;
}
