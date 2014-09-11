/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 465 - "Overflow"
*/

# include <iostream>
# include <cstdio>
# include <cstring>
# include <cmath>
# include <cstdlib>
# include <algorithm>
# include <cctype>

using namespace std;

# define LIMIT 2147483647

int main(void)
{
  char num1[1000],num2[1000],op;
  long double n1,n2;

  while(cin >> num1 >> op >> num2)
    {
      n1 = atof(num1);
      n2 = atof(num2);

      printf("%s %c %s\n",num1,op,num2);

      if(n1 > LIMIT)
        printf("first number too big\n");

      if(n2 > LIMIT)
        printf("second number too big\n");

      if(op=='+' && (n1+n2)>LIMIT)
        printf("result too big\n");
      else if(op=='*' && (n1*n2)>LIMIT)
        printf("result too big\n");
    }

  return 0;
}
