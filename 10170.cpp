/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 10170 - "The Hotel with Infinite Rooms"
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
	unsigned long long s,d,total_member,passed_day;

	while(cin>>s>>d)
	{
	    total_member=s; passed_day=0;

	    while(d>passed_day)
	    {
	        passed_day+=total_member;
	        total_member++;
	    }

	    cout<<total_member-1<<endl;
	}

	return 0;
}
