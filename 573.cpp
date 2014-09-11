/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 573
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
  double h,u,d,f,height,today;
  int day,failure,success;

  while(cin >> h && h)
    {
      cin >> u >> d >> f;

      f = u*(f/100);
      failure = 0;
      success = 0;
      height = 0;

      for(day=0; !failure && !success; day++)
        {
          today = u - f*day;
          if(today < 0)
            today = 0;

          height += today;

          if(height > h)
            {
              success = 1;
              break;
            }

          height -= d;

          if(height < 0)
            {
              failure = 1;
              break;
            }
        }

      if(success)
        printf("success on day %d\n",day+1);
      else if(failure)
        printf("failure on day %d\n",day+1);
    }

  return 0;
}
