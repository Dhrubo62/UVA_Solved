/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11727
*/

# include <iostream>
# include <cstdio>
# include <cstring>
# include <cmath>
# include <cstdlib>
# include <algorithm>
# include <cctype>

using namespace std;

int main(void)
{
	int a[3],t,i=0;

	cin >> t;
	while (i<t)
	{
	    cin >> a[0] >> a[1] >> a[2];

	    sort(a,a+3);

	    printf("Case %d: %d\n",++i,a[1]);
	}

	return 0;
}
