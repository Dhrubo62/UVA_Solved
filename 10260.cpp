/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 10260 - "Soundex"
*/

# include <iostream>
# include <cstdio>
# include <cstring>
# include <string>
# include <cmath>
# include <cstdlib>
# include <algorithm>
# include <cctype>

using namespace std;

int main(void)
{
  string str;

  while(cin >> str)
    {
      int len=str.size(),last=0;

      for(int i=0; i<len; i++)
        {
          if(str[i]=='B' || str[i]=='F' || str[i]=='P' || str[i]=='V')
            {
              if(last!=1)
                {
                  cout << 1;
                  last = 1;
                }
            }
          else if(str[i]=='C' || str[i]=='G' || str[i]=='J' || str[i]=='K' || str[i]=='Q' || str[i]=='S' || str[i]=='X' || str[i]=='Z')
            {
              if(last != 2)
                {
                  cout << 2;
                  last = 2;
                }
            }
          else if(str[i]=='D' || str[i]=='T')
            {
              if(last != 3)
                {
                  cout << 3;
                  last = 3;
                }
            }
          else if(str[i]=='L')
            {
              if(last != 4)
                {
                  cout << 4;
                  last = 4;
                }
            }
          else if(str[i]=='M' || str[i]=='N')
            {
              if(last != 5)
                {
                  cout << 5;
                  last = 5;
                }
            }
          else if(str[i]=='R')
            {
              if(last != 6)
                {
                  cout << 6;
                  last = 6;
                }
            }
          else last = 0;
        }

      cout << endl;
    }

  return 0;
}
