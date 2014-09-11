/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11799
*/

# include <stdio.h>

int main(void)
{
  int t,j;
  scanf("%d",&t);
  for(j=0; j<t; j++)
    {
      int n,array[30000],max,i;

      scanf("%d",&n);
      for(i=0; i<n; i++)
        {
          scanf("%d",&array[i]);
        }

      max=array[0];
      for(i=1; i<n; i++)
        if(array[i]>max)
          max=array[i];

      printf("Case %d: %d\n",j+1,max);
    }

  return 0;
}
