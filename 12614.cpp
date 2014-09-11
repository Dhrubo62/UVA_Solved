/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 12614 - "Earn For Future!"
*/

# include <iostream>
# include <cstdio>
# include <cstring>
# include <string>
# include <cmath>
# include <cstdlib>
# include <algorithm>
# include <cctype>
# include <vector>
# include <queue>

using namespace std;

int main()
{
	int t,csn=0,num,n,highest;

	cin>>t;
	while(t--)
	{
	    highest=0;
	    cin>>n;
	    while(n--)
	    {
	        cin>>num;
	        highest=max(num,highest);
	    }

	    printf("Case %d: %d\n",++csn,highest);
	}

	return 0;
}
