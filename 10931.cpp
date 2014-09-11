/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch
Problem: UVA - 10931 - "Parity"
*/

# include <iostream>
# include <cstdio>
# include <cstring>
# include <cmath>
# include <cstdlib>
# include <algorithm>
# include <cctype>

using namespace std;

int parity;

void print_binary(long long num)
{
  if(!num)
    {
      return ;
    }
  else
    {
      print_binary(num/2);

      cout << num%2;
      if(num%2) parity++;
    }
}

int main(void)
{
  long long num;

  while(cin >> num && num)
    {
      parity=0;

      printf("The parity of ");
      print_binary(num);
      printf(" is %d (mod 2).\n",parity);
    }

  return 0;
}
