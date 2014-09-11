/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11364 - "Optimal Parking"
*/

// ----------------- C headers
# include <cstdio>
# include <cstring>
# include <cmath>
# include <cstdlib>
# include <cctype>

// ----------------- C++ headers
# include <iostream>
# include <string>
# include <algorithm>
# include <vector>
# include <queue>

//------------------ Movements
/*int dx[]={1,-1,0,0}, dy[]={0,0,1,-1};*/ // 4 way movement
/*int dx[]={1,0,-1,0,1,-1,1,-1}, dy[]={0,1,0,-1,1,1,-1,-1};*/ // 8 way movement


using namespace std;

int main()
{
	int t;

	cin>>t;
	while(t--)
	{
	    int MIN=500,MAX=-500,num,n;

	    cin>>n;
	    while(n--)
	    {
	        cin>>num;
	        MAX=max(MAX,num);
	        MIN=min(MIN,num);
	    }

	    cout<<(MAX-MIN)*2<<endl;
	}

	return 0;
}
