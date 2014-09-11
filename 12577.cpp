/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 12577
*/

# include <iostream>
# include <cstdio>
# include <cstring>

using namespace std;

int main(void)
{
  char str[1000000];
  int i=0;

  while(gets(str))
    {
      if(str[0]=='*')
        break;

      if(!strcmp(str,"Hajj"))
        printf("Case %d: Hajj-e-Akbar\n",++i);
      else
        printf("Case %d: Hajj-e-Asghar\n",++i);
    }

  return 0;
}
