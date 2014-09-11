/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 10450 - "World Cup Noise"
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

unsigned long long fibo[51];

void fibo_gen()
{
    fibo[1]=2; fibo[2]=3;
    for(int i=3; i<51; i++) fibo[i]=fibo[i-1]+fibo[i-2];
}

int main()
{
	fibo_gen();

	int n,csn=0,bit_num;

	cin>>n;
	while(csn<n)
	{
	    cin>>bit_num;
	    printf("Scenario #%d:\n%llu\n\n",++csn,fibo[bit_num]);
	}

	return 0;
}
