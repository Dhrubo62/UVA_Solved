/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 484 - "The Department of Redundancy Department"
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
  int n;
  int cnt;
} number[1000001];

int ind;

int main(void)
{
  int num,i;

  while(cin >> num)
    {
      for(i=0; i<ind; i++)
      {
          if(num == number[i].n)
          break;
      }

      if(i == ind)
      {
          number[i].n = num;
          number[i].cnt++;
          ind++;
      }
      else
      {
          number[i].cnt++;
      }
    }

    for(i=0; i<ind; i++)
    {
        printf("%d %d\n",number[i].n,number[i].cnt);
    }

  return 0;
}
