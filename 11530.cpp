/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11530
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
  int i=0,t,press;
  char str[1000000];

  cin >> t;
  getchar();

  while(i<t)
    {
      gets(str);

      press=0;

      for(int j=0; str[j]; j++)
        {
          if(str[j]=='a'||str[j]=='d'||str[j]=='g'||str[j]=='j'||str[j]=='m'||str[j]=='p'||str[j]=='t'||str[j]=='w'||str[j]==' ')
            press++;
          else if(str[j]=='b'||str[j]=='e'||str[j]=='h'||str[j]=='k'||str[j]=='n'||str[j]=='q'||str[j]=='u'||str[j]=='x')
            press += 2;
          else if(str[j]=='c'||str[j]=='f'||str[j]=='i'||str[j]=='l'||str[j]=='o'||str[j]=='r'||str[j]=='v'||str[j]=='y')
            press += 3;
          else
            press += 4;
        }

      printf("Case #%d: %d\n",++i,press);
    }

  return 0;
}
