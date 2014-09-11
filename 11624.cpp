/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11624 - Fire!
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

char grid[1010][1010];
int cost[1010][1010];
bool visit[1010][1010];

struct graph
{
    int x,y,cost;
} next,now;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r,c,sx,sy,ans=-1,i,j;
        queue <graph> q;
        memset(visit,false,sizeof visit);

        //input and record
        cin>>r>>c;
        for(i=0; i<r; i++)
        {
            cin>>grid[i];
            for(j=0; j<c; j++)
            {
                if(grid[i][j]=='F')
                {
                    next.x=i; next.y=j; next.cost=0;
                    q.push(next); visit[i][j]=true;
                }
                else if(grid[i][j]=='J') {sx=i; sy=j;}

                cost[i][j]=-1;
            }
        }

        //fire bfs
        while(!q.empty())
        {
            now=q.front(); q.pop();
            if(now.x==0 || now.x==r-1 || now.y==0 || now.y==c-1) cost[now.x][now.y]=now.cost;

            for(i=0; i<4; i++)
            {
                int x=now.x+dx[i];
                int y=now.y+dy[i];
                if(x>=0 && x<r && y>=0 && y<c && !visit[x][y] && grid[x][y]!='#')
                {
                    next.x=x; next.y=y; next.cost=now.cost+1;
                    q.push(next); visit[x][y]=true;
                }
            }
        }

        //Joe bfs
        memset(visit,false,sizeof visit);
        while(!q.empty()) q.pop();

        next.x=sx; next.y=sy; next.cost=0;
        q.push(next); visit[sx][sy]=true;
        while(!q.empty())
        {
            now=q.front(); q.pop();

            //border cell check
            if((now.x==0 || now.x==r-1 || now.y==0 || now.y==c-1) && (cost[now.x][now.y]>now.cost || cost[now.x][now.y]==-1))
            {
                if(ans==-1) ans=now.cost;
                else ans=min(ans,now.cost);
            }

            for(i=0; i<4; i++)
            {
                int x=now.x+dx[i];
                int y=now.y+dy[i];
                if(x>=0 && x<r && y>=0 && y<c && !visit[x][y] && grid[x][y]!='#')
                {
                    next.x=x; next.y=y; next.cost=now.cost+1;
                    q.push(next); visit[x][y]=true;
                }
            }
        }

        if(ans==-1) cout<<"IMPOSSIBLE"<<endl;
        else cout<<ans+1<<endl;
    }

    return 0;
}
