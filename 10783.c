/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 10783
*/

# include <stdio.h>

int main(void)
{
  int t,T,i,count,one,two;
  scanf("%d", &T);
  for(t=0; t<T; t++)
    {
      scanf("%d",&one);
      scanf("%d",&two);

      count=0;

      for(i=one; i<=two; i++)
        if(i%2)
          count+=i;
      printf("Case %d: %d\n",t+1,count);
    }
  return 0;
}
