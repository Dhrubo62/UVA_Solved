/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 908 - Re-connecting Computer Sites
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

struct edge
{
    int u,v,w;
    edge(int x,int y,int z)
    {
        u=x, v=y, w=z;
    }
};

int par[1000010],n,m,cost;
vector <edge> list;

int parent(int x)
{
    if(par[x]!=x) par[x]=parent(par[x]);
    return par[x];
}

void clean()
{
    cost=0;
    list.clear();
}

int comp(edge a,edge b)
{
    return a.w<b.w;
}

void mst()
{
    sort(list.begin(),list.end(),comp);
    int node=0;
    for(int i=0; i<list.size() && node!=n-1; i++)
    {
        int u=parent(list[i].u), v=parent(list[i].v), w=list[i].w;
        if(u!=v)
        {
            par[u]=v;
            node++;
            cost+=w;
        }
    }
}

int main()
{
    //freopen("input.txt","r",stdin);

    bool first=true;
    while(cin>>n)
    {
        if(first) first=false;
        else cout<<endl;

        for(int i=1; i<=n; i++) par[i]=i;

        cost=0;
        for(int i=0; i<n-1; i++)
        {
            int x;
            cin>>x>>x>>x;
            cost+=x;
        }
        cout<<cost<<endl;

        clean();
        for(int j=0; j<2; j++)
        {
            cin>>m;
            for(int i=0; i<m; i++)
            {
                int u,v,w;
                cin>>u>>v>>w;
                list.push_back(edge(u,v,w));
            }
        }

        mst();
        cout<<cost<<endl;
    }

    return 0;
}
