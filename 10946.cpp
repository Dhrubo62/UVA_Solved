/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 10946 - You want what filled?
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

struct container
{
    char ch;
    int size;
} push;

int r,c,t;
char grid[55][55],key;
bool mark[55][55];
vector <container> list;

void dfs(int x,int y)
{
    mark[x][y]=true; push.size++;
    for(int i=0; i<4; i++)
    {
        int nx=x+dx[i]; int ny=y+dy[i];
        if(nx>=0 && nx<r && ny>=0 && ny<c && grid[nx][ny]==key && !mark[nx][ny]) dfs(nx,ny);
    }
}

int compare(container a,container b)
{
    if(a.size==b.size) return a.ch<b.ch;
    else return a.size>b.size;
}

int main()
{
	while(cin>>r>>c && r && c)
	{
	    int i,j;
	    for(i=0; i<r; i++) cin>>grid[i];

	    memset(mark,false,sizeof mark);
	    list.clear();
	    for(i=0; i<r; i++) for(j=0; j<c; j++) if(grid[i][j]!='.' && !mark[i][j])
	    {
	        key=push.ch=grid[i][j];
	        push.size=0;
	        dfs(i,j);
	        list.push_back(push);
	    }

	    sort(list.begin(),list.end(),compare);
	    printf("Problem %d:\n",++t);
	    for(i=0; i<list.size(); i++) printf("%c %d\n",list[i].ch,list[i].size);
	}

	return 0;
}
