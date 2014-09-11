/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 10763 - "Foreign Exchange"
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
	unsigned long long *from,*to,n,i;

	while(cin>>n && n)
	{
	    //memory allocation
	    from=(unsigned long long *)malloc(n*sizeof(unsigned long long));
	    to=(unsigned long long *)malloc(n*sizeof(unsigned long long));

	    //input
	    for(i=0; i<n; i++) cin>>from[i]>>to[i];

	    //sorting
	    sort(from,from+n); sort(to,to+n);

	    //check n output
	    for(i=0; i<n; i++) if(from[i]!=to[i]) break;
	    i==n ? cout<<"YES"<<endl: cout<<"NO"<<endl;

	    //memory freeing
	    free(from); free(to);
	}

	return 0;
}
