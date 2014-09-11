/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11340 - "Newspaper"
*/

# include <iostream>
# include <cstdio>
# include <cstring>
# include <cmath>
# include <cstdlib>
# include <algorithm>
# include <cctype>

using namespace std;

struct
{
  double value;
  char ch;
} list[1000];

char line[1000000];

int main(void)
{
  long long n;

  cin >> n;
  getchar();
  while(n)
    {
      long long k,i,j;

      cin >> k;
      getchar();
      for(i=0; i<k; i++)
        {
          cin >> list[i].ch >> list[i].value;
          getchar();
        }

      long long m;
      double money=0;
      cin >> m;
      getchar();
      while(m)
        {
          gets(line);

          long long len = strlen(line);

          for(i=0; i<=len; i++)
            {
              for(j=0; j<k; j++)
                {
                  if(line[i] == list[j].ch)
                    {
                      money += list[j].value;
                      break;
                    }
                }
            }

          m--;
        }

      money /= 100;

      printf("%0.2lf$\n",money);

      n--;
    }

  return 0;
}
