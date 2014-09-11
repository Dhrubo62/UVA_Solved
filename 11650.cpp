/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11650
*/

# include <iostream>
# include <cstdio>

using namespace std;

int main(void)
{
  int h1,m1,h2,m2,t;

  cin>>t;

  while(t)
    {
      scanf("%d:%d",&h1,&m1);

      h2=h1-6;
      h2=6-h2;
      if(!h2)
        h2=12;

      if(m1)
        {
          h2--;
          if(!h2)
            h2=12;

          m2=m1-30;
          m2=30-m2;
        }
      else
        m2=0;

      printf("%.2d:%.2d\n",h2,m2);

      t--;
    }

  return 0;
}
