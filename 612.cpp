/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 612 - "DNA Sorting"
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

struct t
{
    string s;
    int v;
} list[110];

int compare(t a, t b)
{
    return a.v<b.v;
}

int main(void)
{
	int n,m,t,i,j,k;
	bool first=true;

	cin>>t;
	while(t)
	{
	    cin>>n>>m;

	    for(i=0; i<m; i++)
	    {
	        cin>>list[i].s;

	        list[i].v=0;
	        for(j=0; j<n; j++)
	        {
	            for(k=j+1; k<n; k++) if(list[i].s[j]>list[i].s[k]) list[i].v++;
	        }
	    }

        stable_sort(list,list+m,compare);

        if(first) first=false;
        else cout<<endl;

        for(i=0; i<m; i++) cout<<list[i].s<<endl;

	    t--;
	}

	return 0;
}
