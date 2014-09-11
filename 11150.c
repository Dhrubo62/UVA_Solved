/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11150
*/

# include <stdio.h>

int main(void)
{
  int cola,bottle,remainder,loan;

  while(scanf("%d",&cola)==1)
    {
      bottle=cola;
      loan=0;

      while(1)
        {
          if(bottle%3 == 2)
            if(!loan)
              {
                bottle++;
                loan=1;
              }

          if(bottle<3)
            break;

          cola+=bottle/3;
          remainder=bottle%3;
          bottle=bottle/3+remainder;
        }

      printf("%d\n",cola);
    }

  return 0;
}
