/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11498
*/

# include <iostream>
# include <cstdio>

using namespace std;

int main(void)
{
  int k,i;
  while(cin>>k && k)
    {
      int x,y,a,b;
      cin>>x>>y;

      for(i=0; i<k; i++)
        {
          cin>>a>>b;
          if(a==x || b==y)
            cout<<"divisa\n";
          else if(a>x)
            {
              if(b>y)
                cout<<"NE\n";
              else
                cout<<"SE\n";
            }
          else if(a<x)
            {
              if(b>y)
                cout<<"NO\n";
              else
                cout<<"SO\n";
            }
        }
    }

  return 0;
}
