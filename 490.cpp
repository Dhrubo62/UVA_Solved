/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA 490
*/

# include <stdio.h>
# include <string.h>

int main(void)
{
  char str[150][150];
  int len[150],n=0,max,i,j;

  //inputing strings
  while(gets(str[n]))
    {
      n++;
    }

  //calculating maximum length
  for(i=0; i<n; i++)
    len[i]=strlen(str[i]);
  max=len[0];
  for(i=1; i<n; i++)
    if(len[i]>max)
      max=len[i];

  //printing
  for(j=0; j<max; j++)
    {
      for(i=n-1; i>=0; i--)
        {
          if(str[i][j])
            printf("%c",str[i][j]);
          else
            printf(" ");
        }

      printf("\n");
    }
  return 0;
}
