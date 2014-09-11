/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11000 - "Bee"
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

long long num[limit];
void fibonacchi_modified(void)
{
    num[1]=1;
    num[2]=2;

    for(long long i=3; i<limit; i++)
    {
        num[i]=num[i-1]+num[i-2]+1;
    }
}

int main(void)
{
    fibonacchi_modified();

    long long n;

    while(cin>>n && n>=0)
    {
        if(!n) cout<<"0 1\n";
        else printf("%lld %lld\n",num[n],num[n]+num[n-1]+1);
    }

	return 0;
}
