/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 722 - Lakes
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

string str;
char number[100];
int sx,sy,r,c,total;
vector <string> grid;
bool mark[110][110];

void dfs(int nx,int ny)
{
    mark[nx][ny]=true;
    if(grid[nx][ny]=='0') total++;

    for(int i=0; i<4; i++)
    {
        int x=nx+dx[i]; int y=ny+dy[i];
        if(x>=0 && x<r && y>=0 && y<c && grid[x][y]=='0' && !mark[x][y]) dfs(x,y);
    }
}

int main()
{
	int t;
	bool first=true;

	cin>>t;
	getchar();
	getline(cin,str);
	while(t--)
	{
	    //input starting position
	    cin>>number; sx=atoi(number); sx--;
	    cin>>number; sy=atoi(number); sy--;
	    getchar();

	    //storage
	    int i;
	    grid.clear();

	    //input grid
	    while(getline(cin,str) && str!="") grid.push_back(str);
	    r=grid.size();
	    c=grid[0].size();

	    //dfs
	    total=0;
	    memset(mark,false,sizeof mark);
	    dfs(sx,sy);

	    //output
	    if(first) first=false;
	    else cout<<endl;
	    cout<<total<<endl;
	}

	return 0;
}
