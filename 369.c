/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch
Problem: UVA 369
*/

# include <stdio.h>

unsigned long long nCr(unsigned long long n,unsigned long long m)
{
  unsigned long long result=1,i;

  if((n-m)<m)
  m=n-m;

  for(i=1;i<=m;i++,n--)
  {
      result*=n;
      result/=i;
  }

  return result;
}

int main(void)
{
  unsigned long long n,m,result,i;

  while(scanf("%llu %llu",&n,&m)!=EOF &&!(!n && !m))
    {
      result=nCr(n,m);
      printf("%llu things taken %llu at a time is %llu exactly.\n",n,m,result);
    }

  return 0;
}
