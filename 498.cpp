/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA 498
*/

# include <stdio.h>
# include <string.h>
# include <math.h>

int main(void)
{
  bool flag;
  int cn,xn,i,j,k,len,n;
  double c[1000],x[1000],result;
  char input[1000000];

  while(gets(input))
    {
      //initialization
      for(i=0; i<1000; i++)
        c[i]=x[i]=0;
      cn=xn=0;

      //inputing the first line consisting of 'c's
      len=strlen(input);
      for(i=0; i<len; )
        {
          if(input[i]>='0' && input[i]<='9')
            {
              for(j=i,k=0; j<len && input[j]!=' '; j++,k++)
                {
                  c[cn]=c[cn]*10+input[j]-48;
                }

              if(i>0 && input[i-1]=='-')
                c[cn]*=-1;

              cn++;
              i+=k;
            }

          else
            i++;
        }

      //inputing the second line consisting of 'x's
      gets(input);
      len=strlen(input);
      for(i=0; i<len; )
        {
          if(input[i]>='0' && input[i]<='9')
            {
              for(j=i,k=0; j<len && input[j]!=' '; j++,k++)
                {
                  x[xn]=x[xn]*10+input[j]-48;
                }

              if(i>0 && input[i-1]=='-')
                x[xn]*=-1;

              xn++;
              i+=k;
            }

          else
            i++;
        }

      //calculation and printing
      n=cn-1;
      flag=false;
      for(i=0; i<xn; i++)
        {
          if(!flag)
            flag=true;
          else
            printf(" ");

          result=0;
          for(j=0; j<cn; j++)
            {
              result= result+ (c[j] * pow(x[i],n-j));
            }
          printf("%0.lf",result);
        }

      printf("\n");
    }

  return 0;
}
