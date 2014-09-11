/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 12250
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
  int i=0;

  while(gets(str) && !(strlen(str)==1 && str[0]=='#'))
    {
      printf("Case %d: ",++i);

      if(!strcmp(str,"HELLO"))
        cout << "ENGLISH\n";
      else if(!strcmp(str,"HOLA"))
        cout << "SPANISH\n";
      else if(!strcmp(str,"HALLO"))
        cout << "GERMAN\n";
      else if(!strcmp(str,"BONJOUR"))
        cout << "FRENCH\n";
      else if(!strcmp(str,"CIAO"))
        cout << "ITALIAN\n";
      else if(!strcmp(str,"ZDRAVSTVUJTE"))
        cout << "RUSSIAN\n";
      else
        cout << "UNKNOWN\n";
    }

  return 0;
}
