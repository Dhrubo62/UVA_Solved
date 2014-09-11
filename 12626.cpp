/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch
Problem: UVA 12626 "I love pizza"
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
  int T;

  cin >> T;
  getchar();

  while(T)
    {
      char str[1000000];
      gets(str);

      int m=0,a=0,r=0,g=0,i=0,t=0;

      for(int j=0; str[j]; j++)
        {
          if(str[j]=='M') m++;
          else if(str[j]=='A') a++;
          else if(str[j]=='R') r++;
          else if(str[j]=='G') g++;
          else if(str[j]=='I') i++;
          else if(str[j]=='T') t++;
        }

      int total = 0;
      while(1)
        {
          m--;
          if(m<0) break;

          a-=3;
          if(a<0) break;

          r-=2;
          if(r<0) break;

          g--;
          if(g<0) break;

          i--;
          if(i<0) break;

          t--;
          if(t<0) break;

          total++;
        }

      cout << total << endl;
      T--;
    }

  return 0;
}
