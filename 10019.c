/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 10019
*/

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int count_one(int num)
{
  int count=0;
  while(num)
    {
      if(num%2)
        count++;
      num=num/2;
    }

  return count;
}

int main(void)
{
  int num,dec,hex,n;
  char digits[100];

  scanf("%d",&n);
  while(n)
    {
      scanf("%d",&num);

      dec=0;
      dec=count_one(num);

      hex=0;
      while(num)
      {
          hex += count_one(num%10);
          num/=10;
      }

      printf("%d %d\n",dec,hex);
      n--;
    }

  return 0;
}
