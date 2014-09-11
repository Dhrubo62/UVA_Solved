/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11710 - Expensive subway
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

int par[410],n,m,node,cost;
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
vector <edge> e;
map <string,int> mp;

int compare(edge a,edge b)
{
    return a.w<b.w;
}

void mst()
{
    node=cost=0;
    sort(e.begin(),e.end(),compare);

    for(int i=0; i<m && node!=n-1; i++)
    {
        int u=parent(e[i].u), v=parent(e[i].v), w=e[i].w;

        if(u!=v)
        {
            par[u]=v;
            node++; cost+=w;
        }
    }
}

int main()
{
    //freopen("input.txt","r",stdin);

    while(cin>>n>>m && !(!n && !m))
    {
        string str;

        mp.clear();
        for(int i=0; i<n; i++)
        {
            cin>>str;

            par[i]=i; mp[str]=i;
        }

        e.clear();
        for(int i=0; i<m; i++)
        {
            int u,v,w;

            cin>>str;
            u=mp[str];

            cin>>str;
            v=mp[str];

            cin>>w;

            e.push_back(edge(u,v,w));
        }
        cin>>str;

        mst();

        if(node==n-1) cout<<cost<<endl;
        else cout<<"Impossible"<<endl;
    }

    return 0;
}
