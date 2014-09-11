/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 10591 - "Happy Number"
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
  int n,i=0;

  cin >> n;

  while(i<n)
    {
      int num,temp;

      cin >> num;

      int number=num;

      temp = num;
      num = 0;
      while(temp)
        {
          num += (temp%10)*(temp%10);
          temp /= 10;
        }

      while(1)
        {
          if(!(num/10))
            {
              if(num==1)
                printf("Case #%d: %d is a Happy number.\n",++i,number);
              else
                printf("Case #%d: %d is an Unhappy number.\n",++i,number);

              break;
            }

          temp = num;
          num = 0;
          while(temp)
            {
              num += (temp%10)*(temp%10);
              temp /= 10;
            }
        }
    }

  return 0;
}
