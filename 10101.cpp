/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 10101
*/

# include <stdio.h>

int main(void)
{
  long long num;
  char def[10][10]= {" ","shata","hajar","lakh","kuti","shata","hajar","lakh","kuti"};
  int i,array[10],t=1;
  bool flag;

  while(scanf("%lld",&num)==1)
    {
      array[0]=num%100;
      num/=100;

      array[1]=num%10;
      num/=10;

      array[2]=num%100;
      num/=100;

      array[3]=num%100;
      num/=100;

      array[4]=num%100;
      num/=100;

      array[5]=num%10;
      num/=10;

      array[6]=num%100;
      num/=100;

      array[7]=num%100;
      num/=100;

      array[8]=num%100;
      num/=100;

      i=8;
      flag=true;
      while(i)
        {
          if(array[i])
            break;

          i--;
        }

      if(i>0)
        flag=false;

      printf("%4d.",t++);
      while(i)
        {
          if(array[i])
            printf(" %d %s",array[i],def[i]);
          else if(i==4)
            printf(" kuti");

          i--;
        }

      if(flag==true && !array[i])
        printf(" 0");
      else if(array[0])
        printf(" %d",array[i]);

        printf("\n");
    }

  return 0;
}
