/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 10533 - "Digit Primes"
*/

# include <iostream>
# include <cstdio>
# include <cstring>
# include <cmath>
# include <cstdlib>
# include <algorithm>
# include <cctype>

using namespace std;

bool prime[1000001];
void sieve(void)
{
  prime[0]=prime[1]=1;
  for(long long i=3; i<1000001; i+=2)
    {
      if(!prime[i])
        {
          for(long long j=i*i; j<1000001; j+=2*i)
            prime[j]=1;
        }
    }
}

int digi[1000001],n_cnt;
void pre_gen_digit_primes(void)
{
  for(long long i=0; i<1000001; i++)
    {
      if(i==2 || (i%2 && !prime[i]))
        {
          long long num=0, temp=i;
          while(temp)
            {
              num += temp%10;
              temp /= 10;
            }

          if(num==2 || (num%2 && !prime[num]))
            n_cnt++;
        }

      digi[i]=n_cnt;
    }
}

int main(void)
{
  sieve();
  pre_gen_digit_primes();

  long long num1,num2,temp;
  int n;

  cin >> n;

  while(n)
    {
      cin >> num1 >> num2;

      if(num1 > num2)
        {
          temp = num1;
          num1 = num2;
          num2 = temp;
        }

      cout << digi[num2] - digi[num1-1] << endl;

      n--;
    }

  return 0;
}
