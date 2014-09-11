/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 657 - The die is cast
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

int h,w,total_dot;
char grid[100][500];
bool mark[100][500], dot[100][500];
vector <int> list;

void dfs_dot(int x,int y)
{
    dot[x][y]=true;

    for(int i=0; i<4; i++)
    {
        int nx=x+dx[i]; int ny=y+dy[i];
        if(nx>=0 && nx<h && ny>=0 && ny<w && grid[nx][ny]=='X' && !dot[nx][ny]) dfs_dot(nx,ny);
    }
}

void dfs_dice(int x,int y)
{
    if(grid[x][y]=='X' && !dot[x][y]) {total_dot++; dfs_dot(x,y);}
    mark[x][y]=true;

    for(int i=0; i<4; i++)
    {
        int nx=x+dx[i]; int ny=y+dy[i];
        if(nx>=0 && nx<h && ny>=0 && ny<w && grid[nx][ny]!='.' && !mark[nx][ny]) dfs_dice(nx,ny);
    }
}

int main()
{
	int t=0;

	while(cin>>w>>h && w && h)
	{
	    //input
	    int i,j;
	    for(i=0; i<h; i++) cin>>grid[i];

	    //refresh
	    list.clear();
	    memset(mark,false,sizeof mark);
	    memset(dot,false,sizeof dot);

	    //search
	    for(i=0; i<h; i++) for(j=0; j<w; j++) if(grid[i][j]!='.' && !mark[i][j])
	    {
	        total_dot=0;
	        dfs_dice(i,j);
	        list.push_back(total_dot);
	    }

	    //output
	    cout<<"Throw "<<++t<<endl;
	    sort(list.begin(),list.end());
	    for(i=0; i<list.size(); i++)
	    {
	        if(i) cout<<" ";
	        cout<<list[i];
	    }
	    cout<<endl<<endl;
	}

	return 0;
}
