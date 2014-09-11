/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 446 - "Kibbles `n' Bits `n' Bits `n' Bits"
*/

# include <iostream>
# include <cstdio>
# include <cstring>
# include <cmath>
# include <cstdlib>
# include <algorithm>
# include <cctype>

using namespace std;

struct bits
{
  unsigned a : 1;
  unsigned b : 1;
  unsigned c : 1;
  unsigned d : 1;
  unsigned e : 1;
  unsigned f : 1;
  unsigned g : 1;
  unsigned h : 1;
  unsigned i : 1;
  unsigned j : 1;
  unsigned k : 1;
  unsigned l : 1;
  unsigned m : 1;
};

union tp
{
  int i;
  struct bits b;
} num1,num2;

int main(void)
{
  char str1[1000000],str2[1000000],ch;
  int n;

  cin >> n;
  while(n)
    {
      cin >> str1 >> ch >> str2;

      int i,result,len;

      num1.i = 0;
      for(i=0; str1[i]; i++)
        {
          if(str1[i] >= 'A' && str1[i] <= 'F')
            num1.i = num1.i*16 + str1[i] - 55;
          else
            num1.i = num1.i*16 + str1[i] - '0';
        }

      num2.i = 0;
      for(i=0; str2[i]; i++)
        {
          if(str2[i] >= 'A' && str2[i] <= 'F')
            num2.i = num2.i*16 + str2[i] - 55;
          else
            num2.i = num2.i*16 + str2[i] - '0';
        }

      result = ch == '+' ? num1.i + num2.i : num1.i - num2.i;

      cout <<num1.b.m<<num1.b.l<<num1.b.k<<num1.b.j<<num1.b.i<<num1.b.h<<num1.b.g<<num1.b.f<<num1.b.e<<num1.b.d<<num1.b.c<<num1.b.b<<num1.b.a;
      cout << ' ' << ch << ' ';
      cout <<num2.b.m<<num2.b.l<<num2.b.k<<num2.b.j<<num2.b.i<<num2.b.h<<num2.b.g<<num2.b.f<<num2.b.e<<num2.b.d<<num2.b.c<<num2.b.b<<num2.b.a;
      printf(" = %d\n",result);

      n--;
    }

  return 0;
}
