/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11945 - "Financial Management"
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

int main(void)
{
	double in,total;
	int n,c=0;
	long ths;

	cin>>n;
	while(c<n)
	{
	    total=0;
	    for(int i=0; i<12; i++)
	    {
	        cin>>in;
	        total += in;
	    }
        total /= 12;

	    ths = (long)total;
        ths /= 1000;
        total -= ths*1000.0;

        printf("%d $",++c);
        if(ths) printf("%ld,",ths);
        printf("%0.2lf\n",total);
	}

	return 0;
}
