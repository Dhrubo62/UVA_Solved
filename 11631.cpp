/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11631 - Dark roads
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

int par[200010],n,e;
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
vector <edge> list;

int compare(edge a,edge b)
{
    return a.w<b.w;
}

int mst()
{
    for(int i=0; i<n; i++) par[i]=i;
    sort(list.begin(),list.end(),compare);

    int cost=0;
    for(int i=0; i<e; i++)
    {
        int u=parent(list[i].u), v=parent(list[i].v), w=list[i].w;

        if(u!=v)
        {
            par[u]=v;
        }
        else cost+=w;
    }

    return cost;
}

int main()
{
    //freopen("input.txt","r",stdin);

    while(cin>>n>>e && !(!n && !e))
    {
        list.clear();
        for(int i=0; i<e; i++)
        {
            int u,v,w;
            cin>>u>>v>>w;
            list.push_back(edge(u,v,w));
        }

        cout<<mst()<<endl;
    }

    return 0;
}
