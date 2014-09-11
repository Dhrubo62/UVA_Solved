/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11879 - "Multiple of 17"
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
	string number;

	while(cin>>number && number!="0")
	{
	    int len=number.size(),remainder=0;

	    for(int i=0; i<len; i++)
	    {
	        remainder = remainder*10 + number[i] - '0';
	        remainder %= 17;
	    }

	    if(remainder) cout<<0<<endl;
	    else cout<<1<<endl;
	}

	return 0;
}
