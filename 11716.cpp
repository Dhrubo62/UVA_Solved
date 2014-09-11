/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11716 - "Digital Fortress"
*/

# include <iostream>
# include <cstdio>
# include <cstring>
# include <cmath>
# include <cstdlib>
# include <algorithm>
# include <cctype>

using namespace std;

int check_sqr(int num)
{
  int temp = (int) pow(num*1.0,0.5);

  return temp*temp == num;
}

int main(void)
{
  char str[1000000];
  char grid[1000][1000];
  int n;

  cin >> n;
  getchar();

  while(n)
    {
      n--;

      gets(str);

      int len = strlen(str), index,i,j;

      if(!check_sqr(len))
        {
          cout << "INVALID\n";
          continue;
        }

      int n = (int) pow(len*1.0,0.5);

      index = 0;
      for(i=0; i<n; i++)
        {
          for(j=0; j<n; j++)
            grid[i][j] = str[index++];
        }

      for(j=0; j<n; j++)
        {
          for(i=0; i<n; i++)
            cout << grid[i][j];
        }

      cout << endl;
    }

  return 0;
}
