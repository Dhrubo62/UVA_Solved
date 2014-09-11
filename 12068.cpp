/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 12068 - "Harmonic Mean"
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

void simplify(long long *a, long long *b)
{
  long long g = __gcd(*a,*b);

  *a /= g;
  *b /= g;
}

int main(void)
{
	int _n=0,N;

	cin >> N;
	while(_n<N)
	{
	    long long n,ind=0,num[1000],i,lcm=1,sum=0;

	    cin >> n;
	    for(i=0; i<n; i++)
	    {
	        cin >> num[ind];

	        if(num[ind]) ind++;
	    }

	    for(i=0; i<ind; i++)
	    {
	        lcm = lcm/__gcd(lcm,num[i]) * num[i];
	    }

	    for(i=0; i<ind; i++)
	    {
	        sum += lcm/num[i];
	    }

	    simplify(&sum,&lcm);

	    simplify(&ind,&sum);

	    ind *= lcm;

	    simplify(&ind,&sum);

	    printf("Case %d: %lld/%lld\n",++_n,ind,sum);
	}

	return 0;
}
