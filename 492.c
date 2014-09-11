/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA 492
*/

# include <stdio.h>

int main(void)
{
  char ch,res;
  int inside=0,consonent=0;

  while(scanf("%c",&ch)==1)
    {
      if(ch>='A'&&ch<='Z' || ch>='a'&&ch<='z')
        {
          if(!inside)
            {
              inside=1;

              if(ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U'||ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
                printf("%c",ch);
              else
                {
                  res=ch;
                  consonent=1;
                }
            }
          else
            {
              printf("%c",ch);
            }
        }
      else
        {
          if(inside)
            {
              inside=0;
              if(consonent)
                {
                  printf("%cay",res);
                  consonent=0;
                }
              else
                printf("ay");
            }

          printf("%c",ch);
        }
    }

  return 0;
}
