/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA 488
*/

# include <stdio.h>

int main(void)
{
  int t,h,f,i,j,first=1;
  scanf("%d",&t);

  while(t)
    {
      if(first)
        first=0;
      else
        printf("\n");

      int one=1;

      scanf("%d%d",&h,&f);
      while(f)
        {
          if(one)
            one=0;
          else
            printf("\n");

          for(i=1; i<=h; i++)
            {
              for(j=1; j<=i; j++)
                printf("%d",i);
              printf("\n");
            }
          for(i=h-1; i>=1; i--)
            {
              for(j=i; j>=1; j--)
                printf("%d",i);
              printf("\n");
            }
          f--;
        }
      t--;
    }

  return 0;
}
