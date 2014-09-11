/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11094 - Continents
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
int dx[]={1,-1,0,0}, dy[]={0,0,1,-1}; // 4 way movement
/*int dx[]={1,0,-1,0,1,-1,1,-1}, dy[]={0,1,0,-1,1,1,-1,-1};*/ // 8 way movement

char grid[25][25],land;
bool mark[25][25];
int r,c,total;

void dfs(int x,int y)
{
    mark[x][y]=true;
    total++;

    for(int i=0; i<4; i++)
    {
        int nx=x+dx[i]; int ny=y+dy[i];

        if(y==0 && ny==-1) ny=c-1;
        else if(y==c-1 && ny==c) ny=0;

        if(nx>=0 && nx<r && ny>=0 && ny<c && grid[nx][ny]==land && !mark[nx][ny]) dfs(nx,ny);
    }
}

int main()
{
	while(cin>>r>>c)
	{
	    int i,j;
	    for(i=0; i<r; i++) cin>>grid[i];

	    memset(mark,false,sizeof mark);

	    cin>>i>>j;
	    land=grid[i][j];
	    dfs(i,j);

	    int MAX=0;
	    for(i=0; i<r; i++) for(j=0; j<c; j++) if(grid[i][j]==land && !mark[i][j])
	    {
	        total=0;
	        dfs(i,j);
	        MAX=max(MAX,total);
	    }

	    cout<<MAX<<endl;
	}

	return 0;
}
