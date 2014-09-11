/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11965
*/

# include <iostream>
# include <cstdio>

using namespace std;

int main(void)
{
  int t,i=0,j;
  char str[1000000];
  bool space,first=true;

  cin>>t;
  getchar();
  while(i<t)
    {
      int n;
      cin>>n;
      getchar();

      if(first)
      first=false;
      else
      cout<<endl;

      cout<<"Case "<<i+1<<":\n";
      while(n)
        {
          gets(str);

          space=false;
          for(j=0; str[j]; j++)
            {
              if(str[j]==' ')
                {
                  if(!space)
                    {
                      cout<<str[j];
                      space=true;
                    }
                }
              else
                {
                  cout<<str[j];
                  space=false;
                }
            }

          cout<<endl;

          n--;
        }

      i++;
    }

  return 0;
}
