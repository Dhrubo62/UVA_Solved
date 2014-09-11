/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11689
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
	int e,f,c,i,rem;

	cin >> i;

	while (i)
	{
	    cin >> e >> f >> c;

	    e += f;
	    f = 0;

	    while (e>=c)
	    {
	        f += e/c;
	        rem = e%c;
	        e = e/c + rem;
	    }

	    cout << f << endl;

	    i--;
	}

	return 0;
}
