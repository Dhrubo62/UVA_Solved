/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 686 - "Goldbach's Conjecture (II)"
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
int prime_list[1000001],ind;

void sieve(void)
{
    prime_list[ind++]=2;

    for(long long i=3; i<1000001; i+=2)
    {
        if(!prime[i])
        {
            prime_list[ind++]=i;

            for(long long j=i*i; j<1000001; j+=2*i)
            {
                prime[j]=1;
            }
        }
    }
}

int main(void)
{
	sieve();

	int i,num,cnt;

	while(cin >> num && num)
	{
	    cnt = 0;

	    for(i=0; i<ind && prime_list[i]<=num/2; i++)
	    {
	        if((num - prime_list[i])==2 || ((num - prime_list[i])%2 && !prime[num - prime_list[i]]))
	        {
	            cnt++;
	        }
	    }

	    cout << cnt << endl;
	}

	return 0;
}
