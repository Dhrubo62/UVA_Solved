/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11172
*/

# include <stdio.h>

int main(void)
{
  int t,T;
  scanf("%d",&T);
  for(t=0; t<T; t++)
    {
      double one,two;
      scanf("%lf %lf",&one,&two);

      if(one==two)
        printf("=\n");
      else if(one>two)
        printf(">\n");
      else if(one<two)
        printf("<\n");

    }
  return 0;
}
