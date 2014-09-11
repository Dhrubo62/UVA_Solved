/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 10041
*/

# include <stdio.h>
# include <stdlib.h>

int compare(int *a, int *b)
{
  return *a>*b;
}

int main(void)
{
  int t;
  scanf("%d",&t);
  while(t)
    {
      int r,array[1000],i;

      scanf("%d",&r);
      for(i=0; i<r; i++)
        {
          scanf("%d",&array[i]);
        }

      qsort(array,r,sizeof(int),compare);

      int mid;
      if(r%2)
        mid=(r+1)/2;
      else
        mid=r/2;

      mid--;

      int distance=0,d;
      for(i=0; i<r; i++)
        if(i!=mid)
          {
            d=array[i]-array[mid];

            if(d<0)
              d*=-1;

            distance+=d;
          }

      printf("%d\n",distance);

      t--;
    }

  return 0;
}
