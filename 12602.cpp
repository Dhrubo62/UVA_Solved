/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 12602 - "Nice Licence Plates"
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
  char str[4];
  int num,value,n;

  cin >> n;
  getchar();

  while(n)
    {
      gets(str);

      value = num = 0;

      for(int i=0; i<3; i++)
        {
          value += (int)pow(26.0,3-(i+1)) * (str[i]-'A');
        }

      for(int i=4; i<8; i++)
        {
          num += (int)pow(10.0,8-(i+1)) * (str[i]-'0');
        }

      if(num-value>=-100 && num-value<=100)
        printf("nice\n");
      else
        printf("not nice\n");

      n--;
    }

  return 0;
}
