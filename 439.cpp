/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 439 - "Knight Moves"
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

bool visited[10][10];
int dx[]={1,2,-1,-2,1,2,-1,-2};
int dy[]={2,1,2,1,-2,-1,-2,-1};

struct stype
{
    int x,y,cost;
};

int main()
{
	int sx,lx;
	char sy,ly;
	while(cin>>sy>>sx>>ly>>lx)
	{
	    sy-='a'; ly-='a'; sx--; lx--;

	    //bfs initialization
	    stype push,now;
	    queue <stype> q;
	    int ans=0,x,y,i;
	    memset(visited,0,sizeof visited);

	    //bfs process
	    push.x=sx; push.y=sy; push.cost=0;
	    q.push(push); visited[sx][sy]=true;
	    while(!q.empty())
	    {
	        now=q.front(); q.pop();

	        if(now.x==lx && now.y==ly) {ans=now.cost; break;}

	        for(i=0; i<8; i++)
	        {
	            x=now.x+dx[i]; y=now.y+dy[i];
	            if(x>=0 && x<8 && y>=0 && y<8 && !visited[x][y])
	            {
	                push.x=x; push.y=y; push.cost=now.cost+1;
	                q.push(push); visited[x][y]=true;
	            }
	        }
	    }

	    //output
	    printf("To get from %c%d to %c%d takes %d knight moves.\n",sy+'a',sx+1,ly+'a',lx+1,ans);
	}

	return 0;
}
