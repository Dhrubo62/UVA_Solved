/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 10812
*/

# include <stdio.h>

void swap(int *a,int *b)
{
  int temp=*a;
  *a=*b;
  *b=temp;
}

int main(void)
{
  int t;
  scanf("%d",&t);
  while(t)
    {
      int s,d,a,b;
      scanf("%d %d",&s,&d);
      a=s+d;
      b=s-d;
      if(a<0 || a%2 || b<0 || b%2)
        printf("impossible\n");
      else
        {
          if(a<b)
            swap(&a,&b);
          printf("%d %d\n",a/2,b/2);
        }
      t--;
    }

  return 0;
}
