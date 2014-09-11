/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 341 - Non-Stop Travel
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

struct pack
{
    int node, cost;

    pack(int x,int y)
    {
        node = x; cost = y;
    }

    bool operator < (const pack& obj) const
    {
        return obj.cost < cost;
    }
};

int n, Start, End, CASE, roads;
int INF = pow(2,31) - 1;

vector <int> G[15], C[15];
int d[15], par[15];

void dijkstra()
{
    // initializing
    d[Start] = 0;
    par[Start] = Start;

    // algorithm
    priority_queue <pack> q;
    q.push( pack( Start, 0 ) );
    while( !q.empty() )
    {
        int u = q.top().node; q.pop();

        if( u == End ) break;

        for(int i=0; i<G[u].size(); i++)
        {
            int v = G[u][i];
            int cost = C[u][i];

            if( d[v] > d[u] + cost )
            {
                d[v] = d[u] + cost;
                par[v] = u;

                q.push( pack( v, d[v] ) );
            }
        }
    }

}

void path(int x)
{
    roads++;

    if( x == Start ) cout << " " << x;
    else
    {
        path( par[x] );
        cout << " " << x;
    }
}

void refresh()
{
    for(int i=1; i<=n; i++)
    {
        G[i].clear();
        C[i].clear();
        d[i] = INF;
        par[i] = -1;
    }
}

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    while( cin>>n && n )
    {
        refresh();

        // inputing graph
        for(int i=1; i<=n; i++)
        {
            int m; cin >> m;
            while( m-- )
            {
                int v, cost;
                cin >> v >> cost;

                G[i].push_back(v);
                C[i].push_back(cost);
            }
        }

        // inputing Start and End
        cin >> Start >> End;

        dijkstra();

        // output
        printf("Case %d: Path =",++CASE);

        roads = 0;
        path(End);
        roads--; if(roads < 1) roads = 1;

        printf("; %d second delay\n", d[End] );
    }

    return 0;
}
