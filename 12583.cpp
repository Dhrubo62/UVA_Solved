/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 12583 - "Memory Overflow"
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
	int N,csn=0,n,k,len,recon;
	string list;

	cin>>N;
	while(csn<N)
	{
	    cin>>n>>k>>list;
	    len=list.size();
	    recon=0;

	    for(int i=0; i<len; i++)
	    {
	        for(int j=i-1; j>=i-k && j>=0; j--)
	        if(list[j]==list[i])
	        {
	            recon++;
	            break;
	        }
	    }

	    printf("Case %d: %d\n",++csn,recon);
	}

	return 0;
}
