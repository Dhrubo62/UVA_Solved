/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch
Problem: UVA 382
*/

# include <stdio.h>

int main(void)
{
  long num,i,total;

  printf("PERFECTION OUTPUT\n");
  while(scanf("%ld",&num) && num)
    {
      total=0;
      for(i=1; i<=num/2; i++)
        if(!(num%i))
          total+=i;

      printf("%5ld  ",num);

      if(total==num)
        printf("PERFECT\n");
      else if(num>total)
        printf("DEFICIENT\n");
      else if(num<total)
        printf("ABUNDANT\n");
    }
  printf("END OF OUTPUT\n");
  return 0;
}
