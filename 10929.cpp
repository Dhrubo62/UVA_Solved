/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch
Problem: UVA - 10929 - "You can say 11"
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
  char num[100000];

  while(gets(num) && !(strlen(num)==1 && num[0]=='0'))
    {
      int remainder=0, i=0, len=strlen(num);

      while(i<len)
        {
          remainder = remainder*10 + num[i++] - '0';

          if(remainder >= 11)
            remainder %= 11;
        }

      if(remainder)
        printf("%s is not a multiple of 11.\n",num);
      else
        printf("%s is a multiple of 11.\n",num);
    }

  return 0;
}
