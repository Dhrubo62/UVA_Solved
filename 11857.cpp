/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11857 - Driving Range
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
    int u, v, cost;

    edge(int x,int y,int z)
    {
        u = x;
        v = y;
        cost = z;
    }
};
vector <edge> edgeList;

int n, m;
int par[1000010];
int parent(int x)
{
    if( par[x] != x ) par[x] = parent( par[x] );
    return par[x];
}

int maxDis, node;
bool compare(edge a, edge b)
{
    return a.cost < b.cost;
}

void mst()
{
    sort(edgeList.begin(), edgeList.end(), compare);

    for(int i=0; i<m && node!=n-1; i++)
    {
        int u=edgeList[i].u, v=edgeList[i].v, cost=edgeList[i].cost;

        if( parent(u) != parent(v) )
        {
            par[ parent(u) ] = parent(v);
            maxDis = max( maxDis, cost );
            node++;
        }
    }
}

void refresh()
{
    edgeList.clear();
    for(int i=0; i<n; i++) par[i] = i;
    maxDis = 0;
    node = 0;
}

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    while(cin >> n >> m && !( !n && !m ))
    {
        // refreshing
        refresh();

        // inputing edge
        for(int i=0; i<m; i++)
        {
            int u, v, cost;
            cin >> u >> v >> cost;
            edgeList.push_back( edge(u, v, cost) );
        }

        // mst
        mst();

        //output
        if( node == n-1 ) cout << maxDis << endl;
        else cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}
