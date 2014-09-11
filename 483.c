/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA 483
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
  char in[10000];

  while(gets(in))
    {
      int i,j,len=strlen(in),wrdln,first=1;
      char word[10000];
      for(i=0; i<len; )
        {
          if(in[i]!=' ')
            {
              wrdln=0;
              for(j=i; in[j]!=' ' && j<len; j++)
                word[wrdln++]=in[j];
              word[wrdln]='\0';

              reverse(word);

              if(first)
              first=0;
              else
              printf(" ");

              printf("%s",word);
              i=i+wrdln;
            }
            else
            i++;
        }
        printf("\n");
    }


  return 0;
}
