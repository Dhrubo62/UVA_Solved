/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 10018
*/

# include <stdio.h>

int palin(unsigned long num)
{
  unsigned long temp=num,reverse=0,rem=0;
  while(temp)
    {
      rem=temp%10;
      reverse=reverse*10+rem;
      temp/=10;
    }

  return reverse==num ? 1 : 0;
}

unsigned long rev(unsigned long num)
{
  unsigned long temp=num,reverse=0,rem=0;
  while(temp)
    {
      rem=temp%10;
      reverse=reverse*10+rem;
      temp/=10;
    }

  return reverse;
}

int main(void)
{
  int t,T;
  scanf("%d",&T);
  for(t=0; t<T; t++)
    {
      unsigned long num;
      scanf("%lu",&num);

      int count=0;
      unsigned long reverse=0;
      while(1)
      {
          reverse=rev(num);
          num=num+reverse;
          count++;
          if(palin(num))
          break;
      }
      printf("%d %lu\n",count,num);
    }

  return 0;
}
