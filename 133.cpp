/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 133 - "The Dole Queue"
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
	int n,k,m,total,a,b,x,y,cnt;

	while(cin>>n>>k>>m && !(!n && !k && !m))
	{
	    total=n;
	    bool list[50],first=true; memset(list,true,sizeof list);
	    x=0; y=n-1;

	    while(total)
	    {
	        cnt=0;
	        while(cnt<k)
	        {
	            if(list[x]) cnt++;
	            if(cnt<k) x++;
	            if(x>n-1) x=0;
	        }

	        cnt=0;
	        while(cnt<m)
	        {
	            if(list[y]) cnt++;
	            if(cnt<m) y--;
	            if(y<0) y=n-1;
	        }

	        if(first) first=false;
	        else cout<<",";
	        if(x!=y) {printf("%3d%3d",x+1,y+1); total-=2;}
	        else {printf("%3d",x+1); total--;}

	        list[x]=false;
	        list[y]=false;
	    }
	    cout<<endl;
	}

	return 0;
}
