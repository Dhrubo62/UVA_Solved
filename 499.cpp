/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA 499
*/

# include <stdio.h>

int main(void)
{
  char str[1000000];
  int count[52],i,max;

  while(gets(str))
    {
      for(i=0; i<52; i++)
        count[i]=0;

      for(i=0; str[i]; i++)
        {
          if(str[i]>='A' && str[i]<='Z')
            count[str[i]-65]++;

          else if(str[i]>='a' && str[i]<='z')
            count[str[i]-71]++;
        }

      max=count[0];
      for(i=1; i<52; i++)
        if(count[i]>max)
          max=count[i];

      for(i=0; i<52; i++)
        if(count[i]==max)
          {
            if(i<=25)
              printf("%c",i+65);

            else
              printf("%c",i+71);
          }

      printf(" %d\n",max);
    }

  return 0;
}
