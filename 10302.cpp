/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 10302
*/

# include <iostream>
# include <cstdio>
# include <cstring>
# include <cmath>
# include <cstdlib>
# include <algorithm>

using namespace std;

int main(void)
{
	long long num,result;

	while(cin>>num)
	{
	    result=0;

	    while(num)
	    {
	        result+=(num*num*num);

	        num--;
	    }

	    cout<<result<<endl;
	}

	return 0;
}
