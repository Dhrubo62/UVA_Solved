/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 10340
*/

# include <stdio.h>
# include <string.h>

# define SIZE 1000000

char key[SIZE],line[SIZE];

int main(void)
{
  while(scanf("%s %s",key,line)!=EOF)
    {
      int len=strlen(key),length=strlen(line);
      int i,j,sub;

      i=0;
      for(j=0; j<length && i<len; j++)
        {
          if(key[i]==line[j])
            i++;
        }
      if(i==len)
        sub=1;
      else
        sub=0;

      if(sub)
        printf("Yes\n");
      else
        printf("No\n");
    }

  return 0;
}
