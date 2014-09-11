/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 10948 - "The primary problem."
*/

# include <iostream>
# include <cstdio>
# include <cstring>
# include <string>
# include <cmath>
# include <cstdlib>
# include <algorithm>
# include <cctype>

using namespace std;

# define limit 1000001

bool prime[limit];
int prime_list[limit],ind;

void sieve(void)
{
    prime_list[ind++] = 2;

    for(long long i=3; i<limit; i+=2)
    {
        if(!prime[i])
        {
            prime_list[ind++] = i;

            for(long long j=i*i; j<limit; j+=2*i)
            {
                prime[j] = 1;
            }
        }
    }
}

int main(void)
{
    sieve();

    long long n,dif;
    bool found;

    while(cin>>n && n)
    {
        found = false;

        printf("%lld:\n",n);

        for(long long i=0; prime_list[i]<=n/2; i++)
        {
            dif = n - prime_list[i];
            if(dif==2 || (dif%2 && !prime[dif]))
            {
                printf("%d+%d\n",prime_list[i],dif);

                found = true;
                break;
            }
        }

        if(!found) cout<<"NO WAY!"<<endl;
    }

	return 0;
}
