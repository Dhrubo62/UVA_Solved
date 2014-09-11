/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 414 - "Machined Surfaces"
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
	int row[12],left,right,n,i,j,min_distance,total_distance;
	char line[30];

	while(cin>>n && n)
	{
	    getchar();  min_distance=500;

	    //input
	    for(i=0; i<n; i++)
	    {
	        gets(line);

	        //counting left part
	        left=0;
	        for(j=0; j<25 && line[j]=='X'; j++) left++;

	        //counting right part
	        right=0;
	        if(left<25) for(j=24; j>=0 && line[j]=='X'; j--) right++;

	        //calculation of distance
	        row[i]=25-left-right; if(row[i]<min_distance) min_distance=row[i];
	    }

	    //final calculation
	    total_distance=0;
	    for(i=0; i<n; i++) total_distance+=row[i]-min_distance;

	    cout<<total_distance<<endl;
	}

	return 0;
}
