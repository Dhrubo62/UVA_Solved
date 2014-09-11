/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 913 - "Joana and the Odd Numbers"
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
	unsigned long long n,num;

	while(cin >> n)
	{
	    num = (n+1)/2*(n+1) - 1;
	    cout << 3*(num-1)-3 << endl;
	}

	return 0;
}
