/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 10921
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
  char str[1000000];

  while (gets(str))
    {
      for (int i=0; str[i]; i++)
        {
          if (str[i]=='A'||str[i]=='B'||str[i]=='C')
            str[i]='2';
          else if (str[i]=='D'||str[i]=='E'||str[i]=='F')
            str[i]='3';
          else if (str[i]=='G'||str[i]=='H'||str[i]=='I')
            str[i]='4';
          else if (str[i]=='J'||str[i]=='K'||str[i]=='L')
            str[i]='5';
          else if (str[i]=='M'||str[i]=='N'||str[i]=='O')
            str[i]='6';
          else if (str[i]=='P'||str[i]=='Q'||str[i]=='R'||str[i]=='S')
            str[i]='7';
          else if (str[i]=='T'||str[i]=='U'||str[i]=='V')
            str[i]='8';
          else if (str[i]=='W'||str[i]=='X'||str[i]=='Y'||str[i]=='Z')
            str[i]='9';
        }

      puts(str);
    }

  return 0;
}
