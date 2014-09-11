/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch
Problem: UVA - 458
*/

# include <stdio.h>
# include <string.h>

int main(void)
{
  char string[10000];

  while(gets(string))
    {
      int i,len=strlen(string);

      for(i=0; i<len; i++)
        string[i]-=7;

      puts(string);
    }

  return 0;
}
