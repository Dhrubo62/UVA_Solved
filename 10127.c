/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 10127
*/

# include <stdio.h>

int main(void)
{
  int n,num,one;

  while(scanf("%d",&num)==1)
    {
      n=one=1;
      while(1)
        {
          if(n<num)
            {
              n=n*10+1;
              one++;
            }

          n=n%num;

          if(!n)
            break;
        }
      printf("%d\n",one);
    }

  return 0;
}
