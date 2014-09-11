/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11417
*/

# include <iostream>
# include <cstdio>
# include <cstring>
# include <cmath>
# include <cstdlib>
# include <algorithm>
# include <cctype>

using namespace std;

long long gcd(long long a, long long b)
{
    if (!a)
    return b;

    if(!b)
    return a;

    long long c;

    while (1)
    {
        c = b%a;

        if (!c)
        break;

        b = a;
        a = c;
    }

    return a;
}

long long g(long long num)
{
    long long G=0;

    for (int i=1; i<num; i++)
    {
        for (int j=i+1; j<=num; j++)
        {
            G += gcd(i, j);
        }
    }

    return G;
}

int main(void)
{
	long long num;

	while(cin >> num && num)
	{
	    cout << g(num) << endl;
	}

	return 0;
}
