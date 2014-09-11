/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 10424
*/

# include <iostream>
# include <cstdio>
# include <cstring>
# include <cmath>
# include <cstdlib>
# include <algorithm>
# include <cctype>

using namespace std;

int value(char *p)
{
  int i,total=0;
  for(i=0; p[i]; i++)
    p[i] = tolower(p[i]);

  for(i=0; p[i]; i++)
    if(p[i]>='a' && p[i]<='z')
      total += p[i]-96;

  while(total>9)
    {
      char num[1000];
      int temp;
      sprintf(num,"%d",total);

      temp=0;
      for(i=0; num[i]; i++)
        temp += num[i]-48;

      total = temp;
    }

  return total;
}

int main(void)
{
  char str1[1000000],str2[1000000];
  double one,two;

  while(gets(str1))
    {
      gets(str2);

      one = (double) value(str1);
      two = (double) value(str2);

      if(one>=two)
        printf("%0.2lf %\n",(two/one)*100);
      else
        printf("%0.2lf %\n",(one/two)*100);
    }

  return 0;
}
