/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11057 - "Exact Sum"
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

bool price[1000002];

int main()
{
	long *p,n,i,money;

	while(cin>>n)
	{
	    p=(long *)malloc(n*sizeof(long));
	    memset(price,0,sizeof price);
	    for(i=0; i<n; i++) {cin>>p[i]; price[p[i]]=true;}
	    cin>>money;

	    sort(p,p+n);
	    for(i=0; i<n && p[i]<=money/2; i++); i--;

	    cout<<"Peter should buy books whose prices are ";
	    for( ; i>=0; i++) if(price[money-p[i]]) {printf("%ld and %ld.\n\n",min(p[i],money-p[i]),max(p[i],money-p[i])); break;}

	    free(p);
	}

	return 0;
}
