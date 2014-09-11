/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11385 - "Da Vinci Code"
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
  long long n,i,j,fibo[1000];

  for(i=0; i<1000; i++)
    {
      if(!i)
        fibo[i] = 1;
      else if(i == 1)
        fibo[i] = 2;
      else
        fibo[i] = fibo[i-1] + fibo[i-2];
    }

  cin >> n;
  getchar();

  while(n)
    {
      char input[1000000], output[1000];
      int cnt;
      long long num[1000], number;

      cin >> cnt;
      getchar();

      for(i=0; i<cnt; i++)
        {
          cin >> num[i];
          getchar();
        }

      // initializing output
      for(i=0; i<1000; i++)
        output[i] = ' ';

      // processing position of fibonacchi numbers
      for(i=0; i<cnt; i++)
        {
          for(j=0; j<1000; j++)
            {
              if(num[i] == fibo[j])
                {
                  num[i] = j;
                  break;
                }
            }
          if(j == 1000)
            num[i] = -10;
        }

      //deleting invalid numbers
      for(i=0; i<cnt; )
        {
          if(num[i] == -10)
            {
              for(j=i; j<cnt-1; j++)
                {
                  num[j] = num[j+1];
                }

              cnt--;
            }
          else
            i++;
        }

      // input
      gets(input);
      long long len = strlen(input);
      int c = 0;

      // formatting output
      int index = 0, max_index = -1;
      for(i=0; i<len && c<cnt; i++)
        {
          if(input[i] >= 'A' && input[i] <= 'Z')
            {
              output[num[index]] = input[i];

              if(num[index] > max_index)
                max_index = num[index];

              index++;
              c++;
            }
        }

      max_index++;
      output[max_index] = '\0';

      printf("%s",output);

      len = strlen(output);
      for(i=0; i<cnt-len; i++)
        cout << ' ';

      cout << endl;

      n--;
    }

  return 0;
}
