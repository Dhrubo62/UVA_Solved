/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 575
*/

# include <stdio.h>
# include <string.h>
# include <math.h>
# include <stdlib.h>

int main(void)
{
  char num[1000];
  int i,len;
  double total;

  while(gets(num) && atoi(num))
    {
      len=strlen(num);
      total=0;

      for(i=0; i<len; i++)
        total += ((num[i]-48)*(pow(2,(len-i))-1));

      printf("%0.lf\n",total);
    }

  return 0;
}
