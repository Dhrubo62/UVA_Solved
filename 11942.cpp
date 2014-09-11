/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11942
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
  int array[1000],ordered,t,i;

  cin >> t;

  cout << "Lumberjacks:\n";

  while (t)
    {
      for (i=0; i<10; i++)
        cin >> array[i];

      ordered = 1;
      if(array[0]>array[1])
        {
          for (i=1; i<9; i++)
            {
              if(array[i] < array[i+1])
                {
                  ordered = 0;
                  break;
                }
            }
        }
      else if (array[0]<array[1])
        {
          for (i=1; i<9; i++)
            {
              if(array[i] > array[i+1])
                {
                  ordered = 0;
                  break;
                }
            }
        }

      if(ordered)
        cout << "Ordered\n";
      else
        cout << "Unordered\n";

        t--;
    }

  return 0;
}
