/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 12403
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
  long long amount=0,tk;
  int t;
  char cmd[1000];

  cin >> t;
  getchar();

  while(t)
    {
      cin >> cmd;

      if(!strcmp(cmd,"donate"))
        {
          cin >> tk;
          getchar();

          amount += tk;
        }
      else if(!strcmp(cmd,"report"))
        cout << amount << endl;

      t--;
    }

  return 0;
}
