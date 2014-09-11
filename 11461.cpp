/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11461
*/

# include <iostream>
# include <cstdio>
# include <cstring>
# include <cmath>
# include <cstdlib>
# include <algorithm>

using namespace std;

int check_square(long long num)
{
  long long root = (long long) pow((double) num, 0.5);

  return num == root*root;
}

int main(void)
{
  long long num1,num2;

  while(cin >> num1 >> num2 && !(!num1 && !num2))
    {
      int j;
      long long cnt=0,start;

      for (j=num1; j<=num2; j++)
        {
          if(check_square(j))
            {
              cnt++;
              start = (long long) pow((double) j, 0.5) +1;
              break;
            }
        }

      if(cnt)
        {
          while(1)
            {
              if(start*start > num2)
                break;
              else
                cnt++;

              start++;
            }
        }

      cout << cnt << endl;
    }

  return 0;
}
