/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11934 - "Magic Formula"
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
	long long a,b,c,d,l,i;

	while(cin>>a>>b>>c>>d>>l && !(!a && !b && !c && !d && !l))
	{
	    long long cnt=0;
	    for(i=0; i<=l; i++) if(!((a*i*i+b*i+c)%d)) cnt++;

	    cout<<cnt<<endl;
	}

	return 0;
}
