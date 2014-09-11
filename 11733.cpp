/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11733 - Airports
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
# include <stack>
# include <map>
# include <sstream>
//}
using namespace std;

//{ ---------- Movements
/*int dx[]={1,-1,0,0}, dy[]={0,0,1,-1};*/ // 4 way movement
/*int dx[]={1,0,-1,0,1,-1,1,-1}, dy[]={0,1,0,-1,1,1,-1,-1};*/ // 8 way movement
//}

struct edge
{
    int u,v,cost;
    edge(int x,int y,int z)
    {
        u=x; v=y; cost=z;
    }
};
vector <edge> edgeList;

int n,m,airports,CASE,airCost,totalCost;

int par[10010];
int parent(int x)
{
    if( par[x]!=x ) par[x] = parent( par[x] );
    return par[x];
}

bool compare(edge a,edge b)
{
    return a.cost < b.cost;
}

void mst()
{
    //clearing the parents
    for(int i=1; i<=n; i++) par[i]=i;

    //initializing
    totalCost=0; airports=n;
    sort(edgeList.begin(), edgeList.end(), compare);

    //tree construction
    for(int i=0; i<edgeList.size() && airports>1 ; i++)
    {
        int u=edgeList[i].u, v=edgeList[i].v, cost=edgeList[i].cost;

        if( parent(u) != parent(v) )
        {
            par[ parent(u) ] = parent(v);
            totalCost += cost;
            airports--;
        }
    }
}

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int t; cin>>t;
    while(t--)
    {
        cin>>n>>m>>airCost;

        //inputing edges
        edgeList.clear();
        while(m--)
        {
            int u,v,cost; cin>>u>>v>>cost;

            if(cost < airCost) edgeList.push_back( edge(u,v,cost) );
        }

        //output
        mst();
        printf("Case #%d: %d %d\n", ++CASE, totalCost + airports*airCost , airports );
    }

    return 0;
}
