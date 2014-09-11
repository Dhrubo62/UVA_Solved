/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 12709 - "Falling Ants"
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
	int n;

	while(cin>>n && n)
	{
	    int l,w,h,volume,high_h=-500,high_volume=-500;

	    while(n--)
	    {
	        cin>>l>>w>>h;

	        if(h>=high_h)
	        {
	            volume=l*w*h;
	            if(h==high_h && volume>high_volume) high_volume=volume;
	            else if(h>high_h) {high_volume=volume; high_h=h;}
	        }
	    }

	    cout<<high_volume<<endl;
	}

	return 0;
}
