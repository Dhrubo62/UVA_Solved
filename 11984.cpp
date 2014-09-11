/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11984
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
	double c,f,d;
	int i=0,t;

	cin >> t;

	while(i<t)
	{
	    cin >> c >> d;

	    f = c*9/5 + 32;
	    f+=d;
	    c = (f-32) *5/9;

	    printf("Case %d: %0.2lf\n",++i,c);
	}

	return 0;
}
