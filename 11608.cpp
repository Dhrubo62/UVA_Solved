/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11608 - "No Problem!"
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
	int prob[12],cntst[12],store,i,csn=0;

	while(cin>>store && store>=0)
	{
	    for(i=0; i<12; i++) cin>>prob[i];
	    for(i=0; i<12; i++) cin>>cntst[i];

	    printf("Case %d:\n",++csn);

	    for(i=0; i<12; i++)
	    {
	        if(cntst[i]<=store)
	        {
	            printf("No problem! :D\n");

	            store-=cntst[i];
	        }
	        else printf("No problem. :(\n");

	        store+=prob[i];
	    }
	}

	return 0;
}
