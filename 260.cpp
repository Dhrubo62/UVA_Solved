/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 260 - Il Gioco dell'X
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

int dx[]={-1,-1,0,0,1,1}; //6 way movement
int dy[]={-1,0,-1,1,0,1};

char grid[210][210];
bool mark[210][210],black;
int csn,n;

void dfs(int nx,int ny)
{
    mark[nx][ny]=true;
    if(nx==n-1) {black=true; return;}
    for(int i=0; i<6 && !black; i++)
    {
        int x=nx+dx[i]; int y=ny+dy[i];
        if(x>=0 && x<n && y>=0 && y<n && grid[x][y]=='b' && !mark[x][y]) dfs(x,y);
    }
}

int main()
{
	while(cin>>n && n)
	{
	    int i;
	    for(i=0; i<n; i++) cin>>grid[i];

	    black=false; memset(mark,false,sizeof mark);
	    for(i=0; i<n && !black; i++) if(grid[0][i]=='b' && !mark[0][i]) dfs(0,i);

	    cout<<++csn<<" ";
	    if(black) cout<<"B"<<endl;
	    else cout<<"W"<<endl;
	}

	return 0;
}
