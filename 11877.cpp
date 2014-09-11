/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11877 - "The Coco-Cola Store"
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
  int bottle,drink,extra_bottle,already_borrowed;

  while(cin >> bottle && bottle)
    {
      drink = 0;
      already_borrowed = 0;
      while(1)
        {
          drink += bottle/3;

          extra_bottle = bottle%3;
          bottle = bottle/3 + extra_bottle;

          if(bottle%3 == 2)
            {
              if(!already_borrowed)
                {
                  bottle++;

                  already_borrowed = 1;
                }
            }

          if(bottle < 3)
            break;
        }

      cout << drink << endl;
    }

  return 0;
}
