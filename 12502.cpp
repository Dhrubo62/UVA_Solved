/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 12502
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
	int t;

	cin >> t;

	while (t)
	{
	    int a,b,c,d;
	    cin >> a >> b >> c;

	    d = c * (2*a-b)/(a+b);

	    if (d<0)
	    d=0;

	    cout << d << endl;

	    t--;
	}

	return 0;
}
