/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 572 - "Oil Deposits"
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

int dx[]={1,-1,0,0,1,-1,1,-1};
int dy[]={0,0,1,-1,1,1,-1,-1};

struct stype
{
    int x,y;
};

int main()
{
	int r,c,i,j,x,y,k;

	while(cin>>r>>c && r && c)
	{
	    char grid[110][110];
	    bool mark[110][110]; memset(mark,0,sizeof mark);

	    for(i=0; i<r; i++) cin>>grid[i];

	    int total_oil_deposits=0;
	    for(i=0; i<r; i++) for(j=0; j<c; j++) if(grid[i][j]=='@' && !mark[i][j])
	    {
	        total_oil_deposits++;

	        //bfs initialization
	        queue <stype> q;
	        stype push,now;

	        //bfs routine
	        push.x=i; push.y=j;
	        q.push(push); mark[i][j]=true;
	        while(!q.empty())
	        {
	            now=q.front(); q.pop();

	            for(k=0; k<8; k++)
	            {
	                x=now.x+dx[k]; y=now.y+dy[k];
	                if(x>=0 && x<r && y>=0 && y<c && grid[x][y]=='@' && !mark[x][y])
	                {
	                    push.x=x; push.y=y;
	                    q.push(push); mark[x][y]=true;
	                }
	            }
	        }
	    }

	    cout<<total_oil_deposits<<endl;
	}

	return 0;
}
