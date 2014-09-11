/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA 494
*/

# include <stdio.h>
# include <string.h>

int main(void)
{
  char str[10000];

  while(gets(str))
    {
      int count=0,i,len=strlen(str);
        int in=0;
      for(i=0; i<len; i++)
        if((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z'))
        {
            if(!in)
            {
                count++;
                in=1;
            }
        }
        else
        {
            in=0;
        }

          printf("%d\n",count);
    }

  return 0;
}
