/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11185
*/

# include <iostream>
# include <cstdio>
# include <cstring>
# include <cmath>
# include <cstdlib>
# include <algorithm>
# include <cctype>

using namespace std;

void print_ternary(long long num)
{
  if(!num)
    {
      return ;
    }
  else
    {
      print_ternary(num/3);

      cout << num%3;
    }
}

int main(void)
{
  long long num;

  while(cin >> num && num>=0)
    {
      if(!num)
        printf("0\n");
      else
        {
          print_ternary(num);

          cout << endl;
        }
    }

  return 0;
}
