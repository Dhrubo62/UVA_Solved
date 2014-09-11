/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 10050
*/

# include <stdio.h>

int main(void)
{
  int t;
  scanf("%d",&t);
  while(t)
    {
      int d,p,i,j,day[10000],count;

      scanf("%d",&d);
      for(i=0; i<d; i++)
        day[i]=1;

      scanf("%d",&p);
      while(p)
        {
          int peak;
          scanf("%d",&peak);
          for(i=1,j=0; i<=d; i++)
            {
              j++;
              if(j==peak)
                {
                  if((i%7)!=0 && (i%7)!=6)
                    {
                      day[i-1]=0;
                    }

                  j=0;
                }
            }

          p--;
        }

      count=0;
      for(i=0; i<d; i++)
        if(!day[i])
          count++;

          printf("%d\n",count);

      t--;
    }

  return 0;
}
