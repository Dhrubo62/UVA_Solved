/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11953 - "Battleships"
*/

# include <iostream>
# include <cstdio>
# include <cstring>
# include <string>
# include <cmath>
# include <cstdlib>
# include <algorithm>
# include <cctype>
# include <vector>
# include <queue>

using namespace std;

struct stype
{
    int x,y;
};

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

int main()
{
	int t,csn=0,n,i;

	cin>>t;
	while(csn<t)
	{
	    //input
	    cin>>n;
	    char grid[110][110]; for(i=0; i<n; i++) cin>>grid[i];

	    //checking
	    int total_ship=0,j,k;
	    bool mark[110][110]; memset(mark,false, sizeof mark);
	    for(i=0; i<n; i++) for(j=0; j<n; j++) if(grid[i][j]=='x' && !mark[i][j])
	    {
	        total_ship++;
	        //bfs initialization
	        int x,y;
	        stype push,now;
	        queue <stype> q;

	        //bfs routine
	        push.x=i; push.y=j;
	        q.push(push); mark[i][j]=true;
	        while(!q.empty())
	        {
	            now=q.front(); q.pop();

	            for(k=0; k<4; k++)
	            {
	                x=now.x+dx[k]; y=now.y+dy[k];
	                if(x>=0 && x<n && y>=0 && y<n && !mark[x][y] && grid[x][y]!='.')
	                {
	                    push.x=x; push.y=y;
	                    q.push(push); mark[x][y]=true;
	                }
	            }
	        }
	    }

	    printf("Case %d: %d\n",++csn,total_ship);
	}

	return 0;
}
