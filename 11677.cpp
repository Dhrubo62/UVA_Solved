/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11677
*/

# include <iostream>
# include <cstdio>

using namespace std;

int main(void)
{
  int h1,m1,h2,m2;
  while(cin>>h1>>m1>>h2>>m2)
    {
      if(!h1 && !m1 && !h2 && !m2)
        break;

      if(h2<h1 || (h2==h1 && m2<m1))
        h2+=24;

      cout<<(h2*60+m2)-(h1*60+m1)<<endl;
    }

  return 0;
}
