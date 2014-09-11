/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11192
*/

# include <stdio.h>
# include <string.h>

void reverse(char *p)
{
  char temp[10000];
  int i,len=strlen(p);

  for(i=0; i<len; i++)
    temp[i]=p[len-i-1];
  temp[i]='\0';

  strcpy(p,temp);
}

int main(void)
{
  int g,len,ln,i,j,k;
  char line[10000],str[10000];

  while(scanf("%d",&g)!=EOF && g)
    {
      getchar();
      gets(line);
      len=strlen(line);
      ln=len/g;

      for(i=0; i<g; i++)
        {
          for(j=(ln*i),k=0; k<ln; k++,j++)
            {
              str[k]=line[j];
            }
          str[k]='\0';

          reverse(str);
          printf(str);
        }
      printf("\n");
    }

  return 0;
}
