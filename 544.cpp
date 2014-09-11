/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 544 - Heavy Cargo
*/

//{ ---------- C headers
# include <cstdio>
# include <cstring>
# include <cmath>
# include <cstdlib>
# include <cctype>
//}

//{ ---------- C++ headers
# include <iostream>
# include <string>
# include <algorithm>
# include <vector>
# include <queue>
# include <map>
//}
using namespace std;

//{ ---------- Movements
/*int dx[]={1,-1,0,0}, dy[]={0,0,1,-1};*/ // 4 way movement
/*int dx[]={1,0,-1,0,1,-1,1,-1}, dy[]={0,1,0,-1,1,1,-1,-1};*/ // 8 way movement
//}

int n,m,ttl,d,cost,csn;
string str;
map <string,int> mp;
bool mark[210];

int par[210];
int parent(int x)
{
    if(par[x]!=x) par[x]=parent(par[x]);
    return par[x];
}

struct edge
{
    int u,v,w;
    edge(int x,int y,int z)
    {
        u=x, v=y, w=z;
    }
};
vector <edge> e,adjcnt[210];

int comp(edge a,edge b)
{
    return a.w>b.w;
}

void mst()
{
    sort(e.begin(),e.end(),comp);

    int node=0;
    for(int i=0; i<e.size() && node!=n-1; i++)
    {
        int u=e[i].u, v=e[i].v, w=e[i].w;

        if(parent(u)!=parent(v))
        {
            par[parent(u)]=parent(v);
            node++;

            adjcnt[u].push_back(edge(u,v,w));
            adjcnt[v].push_back(edge(v,u,w));
        }
    }
}

void dfs(int u,int w)
{
    mark[u]=true;

    if(u==d) {cost=w; return;}

    for(int i=0; i<adjcnt[u].size() && cost==-1; i++)
    {
        int v=adjcnt[u][i].v, c=adjcnt[u][i].w;
        if(!mark[v]) dfs(v,min(w,c));
    }
}

int main()
{
    //freopen("input.txt","r",stdin);

    while(cin>>n>>m && !(!n && !m))
    {
        //input
        ttl=0;
        while(m--)
        {
            int u,v,w;

            cin>>str;
            if(mp.find(str)==mp.end()) mp[str]=ttl, par[ttl]=ttl, adjcnt[ttl].clear(), ttl++;
            u=mp[str];

            cin>>str;
            if(mp.find(str)==mp.end()) mp[str]=ttl, par[ttl]=ttl, adjcnt[ttl].clear(), ttl++;
            v=mp[str];

            cin>>w;

            e.push_back(edge(u,v,w));
        }

        //mst and adjacency list construction
        mst();

        //dfs
        int u;
        cin>>str; u=mp[str];
        cin>>str; d=mp[str];

        cost=-1;
        memset(mark,false,sizeof mark);
        dfs(u,10010);

        //result
        printf("Scenario #%d\n",++csn);
        printf("%d tons\n\n",cost);

        //clear
        mp.clear();
        e.clear();
    }

    return 0;
}
