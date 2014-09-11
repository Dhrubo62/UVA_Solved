/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 10653 - "Bombs! NO they are Mines!!"
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
int dx[]={1,-1,0,0}, dy[]={0,0,1,-1}; // 4 way movement
/*int dx[]={1,0,-1,0,1,-1,1,-1}, dy[]={0,1,0,-1,1,1,-1,-1};*/ // 8 way movement

using namespace std;

struct stype
{
    int x,y,cost;
};

int main()
{
	int r,c,i;

	while(cin>>r>>c && r && c)
	{
	    //grid set
	    bool bomb[1010][1010],mark[1010][1010];
	    memset(bomb,false,sizeof bomb); memset(mark,false,sizeof mark);

	    //input mines
	    int query,x,y,n;
	    cin>>query;
	    while(query--)
	    {
	        cin>>x>>n;
	        while(n--)
	        {
	            cin>>y; bomb[x][y]=true;
	        }
	    }

	    //input start and end
	    int fx,fy;
	    cin>>x>>y>>fx>>fy;

	    //bfs initialization
	    stype push,now;
	    queue <stype> q;
	    int ans;

	    //bfs routine
	    push.x=x; push.y=y; push.cost=0;
	    q.push(push); mark[x][y]=true;
	    while(!q.empty())
	    {
	        now=q.front(); q.pop();

	        if(now.x==fx && now.y==fy) {ans=now.cost; break;}

	        for(i=0; i<4; i++)
	        {
	            x=now.x+dx[i]; y=now.y+dy[i];
	            if(x>=0 && x<r && y>=0 && y<c && !bomb[x][y] && !mark[x][y])
	            {
	                push.x=x; push.y=y; push.cost=now.cost+1;
	                q.push(push); mark[x][y]=true;
	            }
	        }
	    }

	    //output
	    cout<<ans<<endl;
	}

	return 0;
}
