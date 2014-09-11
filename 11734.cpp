/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11734
*/

# include <iostream>
# include <cstdio>
# include <cstring>
# include <cmath>
# include <cstdlib>
# include <algorithm>

using namespace std;

int main(void)
{
  char str[1000000],judge[1000000];
  int len,t,i=0;
  bool space;

  cin >> t;
  getchar();

  while(i<t)
    {
      gets(str);
      gets(judge);

      printf("Case %d: ",++i);

      len=strlen(str);
      space=false;

      for(int j=0; j<len; )
        {
          if(str[j]==' ')
            {
              if(!space)
                space=true;

              for(int k=j; k<len-1; k++)
                str[k]=str[k+1];

              str[--len]='\0';
            }
            else
            j++;
        }

      if(!strcmp(str,judge))
        {
          if(!space)
            cout<<"Yes\n";
          else
            cout<<"Output Format Error\n";
        }
      else
        cout<<"Wrong Answer\n";
    }

  return 0;
}
