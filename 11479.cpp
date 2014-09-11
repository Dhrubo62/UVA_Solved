/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11479
*/

# include <iostream>
# include <cstdio>

using namespace std;

int main(void)
{
  int t,i=0;
  cin>>t;
  while(i<t)
    {
      long long a,b,c;

      cin>>a>>b>>c;

      printf("Case %d: ",++i);

      if(a+b<=c || b+c<=a || c+a<=b)
        puts("Invalid");
      else
        {
          if(a==b && b==c)
            puts("Equilateral");
          else if((a==b && b!=c)||(b==c && c!=a)||(c==a && a!=b))
            puts("Isosceles");
          else
            puts("Scalene");
        }
    }

  return 0;
}
