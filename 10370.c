/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 10370
*/

# include <stdio.h>

int main(void)
{
  int c;
  scanf("%d", &c);
  while(c)
    {
      double *p,total=0,count=0;
      int n,i;
      scanf("%d", &n);

      p=(double *)malloc(n*sizeof(double));
      for(i=0; i<n; i++)
        {
          scanf("%lf",&p[i]);
          total += p[i];
        }

        total/=n;
        for(i=0; i<n; i++)
        if(p[i]>total)
        count++;

        printf("%.3lf%%\n",(count/n)*100);
        c--;
    }

  return 0;
}
