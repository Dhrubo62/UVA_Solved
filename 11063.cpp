/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11063 - "B2-Sequence"
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

int main()
{
	int n,*list,results[100000],ind,sum,i,j,k,c=0;
	bool b2,first;

	while(cin>>n)
	{
	    list=(int *)malloc(n*sizeof(int));

	    //input
	    b2=true; first=true;
	    for(i=0; i<n; i++)
	    {
	        cin>>list[i];
	        //initial check
	        if(list[i]<1) b2=false;
	        if(first) first=false;
	        else if(list[i]<=list[i-1]) b2=false;
	    }

	    //check if already not declared invalid
	    if(b2)
	    {
	        first=true; ind=0;
            for(i=0; i<n && b2; i++)
            {
                for(j=i; j<n; j++)
                {
                    sum=list[i]+list[j];
                    if(first) {first=false; results[ind++]=sum;}
                    else
                    {
                        for(k=0; k<ind && sum!=results[k]; k++);
                        if(k==ind) results[ind++]=sum;
                        else {b2=false; break;}
                    }
                }
            }
	    }

	    //print
	    if(b2) printf("Case #%d: It is a B2-Sequence.\n\n",++c);
	    else printf("Case #%d: It is not a B2-Sequence.\n\n",++c);
	}

	return 0;
}
