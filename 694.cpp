/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 694 - "The Collatz Sequence"
*/

# include <iostream>
# include <cstdio>
# include <cstring>
# include <cmath>
# include <cstdlib>
# include <algorithm>
# include <cctype>

using namespace std;

long long count_step(long long num, long long limit)
{
  long long cnt=1;

  while(1)
    {
      if(num==1 || num>limit)
        break;

      if(!(num%2))
        num /= 2;
      else
        num = num*3 + 1;

      if(num<=limit)
        cnt++;
    }

  return cnt;
}

int main(void)
{
  long long num,limit,case_count=0;

  while(cin >> num >> limit)
    {
      if(num<0 && limit<0)
        break;

      printf("Case %lld: A = %lld, limit = %lld, number of terms = %lld\n",++case_count,num,limit,count_step(num,limit));
    }

  return 0;
}
