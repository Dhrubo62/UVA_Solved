/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11244 - "Counting Stars"
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
int dx[]={1,0,-1,0,1,-1,1,-1}, dy[]={0,1,0,-1,1,1,-1,-1}; // 8 way movement

int r,c,total_block;
char grid[500][110];
bool mark[500][110];

void dfs(int nx,int ny)
{
    mark[nx][ny]=true;
    total_block++;

    for(int i=0; i<8; i++)
    {
        int x=nx+dx[i]; int y=ny+dy[i];
        if(x>=0 && x<r && y>=0 && y<c && grid[x][y]=='*' && !mark[x][y]) dfs(x,y);
    }
}

int main()
{
	while(cin>>r>>c && r && c)
	{
	    int i;
	    for(i=0; i<r; i++) cin>>grid[i];

	    int total=0,j;
	    memset(mark,false,sizeof mark);
	    for(i=0; i<r; i++) for(j=0; j<c; j++) if(grid[i][j]=='*' && !mark[i][j])
	    {
	        total_block=0;
	        dfs(i,j);
	        if(total_block==1) total++;
	    }

	    cout<<total<<endl;
	}

	return 0;
}
