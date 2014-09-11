/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11960 - "Divisor Game"
*/

# include <iostream>
# include <cstdio>
# include <cstring>
# include <cmath>
# include <cstdlib>
# include <algorithm>
# include <cctype>

using namespace std;

int cnt[1000001];

void pre_gen_divisor_count(void)
{
  for(long long i=2; i<1000001; i++)
    {
      for(long long j=2*i; j<1000001; j+=i)
        cnt[j]++;
    }
}

int maximum[1000001];

void pre_gen_maximum_divisor_number_list(void)
{
  maximum[1]=1;

  for(long long i=2; i<1000001; i++)
    {
      if(cnt[i] >= cnt[maximum[i-1]])
        maximum[i]=i;
      else
        maximum[i]=maximum[i-1];
    }
}

int main(void)
{
  pre_gen_divisor_count();

  pre_gen_maximum_divisor_number_list();

  int n;
  cin >> n;

  while(n)
    {
      long num;

      cin >> num;

      cout << maximum[num] << endl;

      n--;
    }

  return 0;
}
