/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11917
*/

# include <iostream>
# include <cstdio>
# include <cstring>
# include <cmath>
# include <cstdlib>
# include <algorithm>
# include <cctype>

using namespace std;

struct
{
  char name[1000];
  int days;
} subject[1000];

int main(void)
{
  int i=0,j,t,d,days;
  char sub[1000];

  cin >> t;
  while(i<t)
    {
      int n;

      cin >> n;
      for(j=0; j<n; j++)
        cin >> subject[j].name >> subject[j].days;

      cin >> d >> sub;

      printf("Case %d: ",++i);

      days=0;

      for(j=0; j<n; j++)
        if(!strcmp(sub,subject[j].name))
          {
            days = subject[j].days;
          }

      if(!days || days > d+5)
        printf("Do your own homework!\n");
      else if(days > d && days <= d+5)
        printf("Late\n");
      else if(days <= d)
        printf("Yesss\n");
    }

  return 0;
}
