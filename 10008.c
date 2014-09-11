/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 10008
*/

# include <stdio.h>
# include <ctype.h>
# include <stdlib.h>

int compare(int *a, int *b)
{
  return *b - *a;
}

int des(int *a, int *b)
{
  return *a - *b;
}

int main(void)
{
  int T,i,j;
  scanf("%d", &T);
  getchar();

  int count[26];
  for(i=0; i<26; i++)
    count[i]=0;

  while(T)
    {
      char str[1000];
      gets(str);
      for(i=0; str[i]; i++)
        str[i]=toupper(str[i]);


      for(i=0; str[i]; i++)
        if(str[i]>='A' && str[i]<='Z')
          count[str[i]-65]++;

      T--;
    }


  int max;

  max=count[0];
  for(i=0; i<26; i++)
    if(count[i]>max)
      max=count[i];

  while(max)
    {
      for(i=0; i<26; i++)
        if(max==count[i])
          printf("%c %d\n",i+65,count[i]);

      max--;
    }

  return 0;
}
