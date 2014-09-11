/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11854
*/

# include <iostream>
# include <cstdio>

using namespace std;

int main(void)
{
  int a,b,c;
  while(cin>>a>>b>>c)
    {
      if(!a && !b && !c)
        break;

      if((a*a+b*b==c*c) || (a*a+c*c==b*b) || (c*c+b*b==a*a))
        printf("right\n");
      else
        printf("wrong\n");
    }

  return 0;
}
