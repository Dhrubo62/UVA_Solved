/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11377 - Airport Setup
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
# include <set>
//}
using namespace std;

//{ ---------- Movements
/*int dx[]={1,-1,0,0}, dy[]={0,0,1,-1};*/ // 4 way movement
/*int dx[]={1,0,-1,0,1,-1,1,-1}, dy[]={0,1,0,-1,1,1,-1,-1};*/ // 8 way movement
//}

int INF = pow( 2, 31 ) - 1;

struct pack
{
    int node, cost;
    pack( int NODE, int COST )
    {
        node = NODE;
        cost = COST;
    }
    bool operator < ( const pack& obj ) const
    {
        return obj.cost < cost;
    }
};

int n, Start, End;
vector < int > graph[2010];
map < int , bool > air;

int d[2010];

void dijkstra()
{
    // clearing distance array
    for(int i=1; i<=n; i++) d[i] = INF;
    d[ Start ] = 1 - air[ Start ];

    // algorithm
    priority_queue < pack > q;
    q.push( pack( Start, d[Start] ) );
    while( !q.empty() )
    {
        int u = q.top().node; q.pop();

        if( u == End ) break;

        for(int i=0; i<graph[u].size(); i++)
        {
            int v = graph[u][i];
            int cost = 1 - air[v];

            if( d[v] > d[u] + cost )
            {
                d[v] = d[u] + cost;
                q.push( pack( v, d[v] ) );
            }
        }
    }
}

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int CASE = 1, t; cin >> t;
    while( t-- )
    {
        int m, k; cin >> n >> m >> k;

        // clearing airports and inputing them
        air.clear();
        while( k-- )
        {
            int port; cin >> port;
            air[ port ] = true;
        }

        // clearing and inputing graph
        for(int i=1; i<=n; i++) graph[i].clear();
        while( m-- )
        {
            int u, v; cin >> u >> v;

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        // queries and output
        cout << "Case " << CASE++ << ":" << endl;
        int queries; cin >> queries;
        while( queries-- )
        {
            cin >> Start >> End;

            if( Start == End ) { cout << 0 << endl; continue; }

            dijkstra();
            if( d[End] == INF ) cout << -1 << endl;
            else cout << d[End] << endl;
        }
        cout << endl;
    }

    return 0;
}
