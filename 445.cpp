/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch
Problem: UVA - 445
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
  char str[1000000];
  int num;
  int i,j,len;

  while(gets(str))
    {
      for(i=0; str[i]; )
        {
          num = 0;
          while(str[i]>='0'&&str[i]<='9')
            {
              num += str[i++]-48;
            }
          for(j=0; j<num; j++)
            {
              if(str[i]=='b')
                cout << ' ';
              else
                cout << str[i];
            }
          if(str[i]=='!')
            cout << endl;
          i++;
        }

      cout << endl;

    }

  return 0;
}
