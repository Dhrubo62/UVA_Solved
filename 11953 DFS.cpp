/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11953 - "Battleships" - DFS
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

char grid[110][110];
bool mark[110][110];
int n;

void dfs(int nx,int ny)
{
    mark[nx][ny]=true;

    for(int i=0; i<8; i++)
    {
        int x=nx+dx[i]; int y=ny+dy[i];
        if(x>=0 && x<n && y>=0 && y<n && grid[x][y]!='.' && !mark[x][y]) dfs(x,y);
    }
}

int main()
{
	int t,csn=0;
	cin>>t;
	while(csn<t)
	{
	    cin>>n;
	    int i;
	    for(i=0; i<n; i++) cin>>grid[i];

	    memset(mark,false,sizeof mark);
	    int j,total=0;
	    for(i=0; i<n; i++) for(j=0; j<n; j++) if(grid[i][j]=='x' && !mark[i][j])
	    {
	        total++;
	        dfs(i,j);
	    }

	    printf("Case %d: %d\n",++csn,total);
	}

	return 0;
}
