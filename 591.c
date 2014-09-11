/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 591
*/

# include <stdio.h>
# include <stdlib.h>

int main(void)
{
  int n,i,*array,count,dif,set=0;
  while(scanf("%d",&n) && n)
    {
      set++;
      count=0;
      dif=0;
      array=(int *)malloc(n*sizeof(int));

      for(i=0; i<n; i++)
        {
          scanf("%d",&array[i]);
          count+=array[i];
        }

      count/=n;

       for(i=0; i<n; i++)
       {
           if(array[i]>count)
           dif += (array[i]-count);
       }

       printf("Set #%d\nThe minimum number of moves is %d.\n\n",set,dif) ;
    }

  return 0;
}
