/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 673 - "Parentheses Balance"
*/

# include <iostream>
# include <cstdio>
# include <cstring>
# include <cmath>
# include <cstdlib>
# include <algorithm>
# include <cctype>

using namespace std;

int main(void)
{
  char str[1000];
  int stk[1000],ind,n,len,i;

  cin >> n;
  getchar();

  while(n)
    {
      gets(str);
      len = strlen(str);

      ind = 0;
      stk[0]=0;
      for(i=0; i<len; i++)
        {
          if(str[i]=='(')
            {
              stk[ind++]=1;
            }
          else if(str[i]=='[')
            {
              stk[ind++]=2;
            }
          else if(str[i]==')')
            {
              if(stk[--ind]!=1)
                {
                  break;
                }
                else
                stk[ind]=0;
            }
          else if(str[i]==']')
            {
              if(stk[--ind]!=2)
                {
                  break;
                }
                else
                stk[ind]=0;
            }
        }

        if(!ind && !stk[ind])
        printf("Yes\n");
        else
        printf("No\n");

        n--;
    }

  return 0;
}
