/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 532 - Dungeon Master
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
# include <map>

using namespace std;

//------------------ Movements
/*int dx[]={1,-1,0,0}, dy[]={0,0,1,-1};*/ // 4 way movement
/*int dx[]={1,0,-1,0,1,-1,1,-1}, dy[]={0,1,0,-1,1,1,-1,-1};*/ // 8 way movement

int dx[]={-1,1,0,0,0,0}; //6 way 3D motion
int dy[]={0,0,-1,1,0,0};
int dz[]={0,0,0,0,-1,1};

struct stype
{
    int x,y,z,cost;
};

int main()
{
	int l,r,c;

	while(cin>>l>>r>>c && l && r && c)
	{
	    //storage
	    int i,j,k,x,y,z;
	    char grid[35][35][35];

	    //input
	    for(i=0; i<l; i++) for(j=0; j<r; j++)
	    {
	        cin>>grid[i][j];
	        for(k=0; k<c; k++) if(grid[i][j][k]=='S') {x=j; y=k; z=i;}
	    }

	    //bfs initialization
	    bool mark[35][35][35]; memset(mark,false,sizeof mark);
	    stype push,now;
	    queue <stype> q;
	    int ans=-1;

	    //bfs process
	    push.x=x; push.y=y; push.z=z; push.cost=0;
	    q.push(push); mark[z][x][y]=true;
	    while(!q.empty())
	    {
	        now=q.front(); q.pop();

	        if(grid[now.z][now.x][now.y]=='E') {ans=now.cost; break;}

	        for(i=0; i<6; i++)
	        {
	            x=now.x+dx[i];
	            y=now.y+dy[i];
	            z=now.z+dz[i];
	            if(x>=0 && x<r && y>=0 && y<c && z>=0 && z<l && grid[z][x][y]!='#' && !mark[z][x][y])
	            {
	                push.x=x; push.y=y; push.z=z; push.cost=now.cost+1;
	                q.push(push); mark[z][x][y]=true;
	            }
	        }
	    }

	    //output
	    if(ans==-1) cout<<"Trapped!"<<endl;
	    else printf("Escaped in %d minute(s).\n",ans);
	}

	return 0;
}
