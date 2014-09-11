/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 10986 - Sending email
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

vector <long long> graph[20010], cost[20010];
long long n, m, Start, End;
long long d[20010];
long long INF = pow( 2, ( (sizeof (long long)) * 8 ) -1) - 1;

void refresh()
{
    for(long long i = 0; i<n; i++)
    {
        d[i] = INF;
        graph[i].clear();
        cost[i].clear();
    }
}

struct pack
{
    long long node, c;
    pack(long long a, long long b)
    {
        node = a;
        c = b;
    }
    bool operator < (const pack& obj) const
    {
        return obj.c < c;
    }
};

void dijkstra()
{
    d[ Start ] = 0;

    priority_queue <pack> q;
    q.push( pack( Start, d[ Start ] ) );
    while( !q.empty() )
    {
        long long u = q.top().node; q.pop();

        if( u == End ) break;

        for(long long i = 0; i<graph[u].size(); i++)
        {
            long long v = graph[u][i];
            long long c = cost[u][i];

            if( d[v] > d[u] + c )
            {
                d[v] = d[u] + c;
                q.push( pack( v, d[v] ) );
            }
        }
    }
}

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    long long CASE = 1;
    long long t; cin >> t;
    while( t-- )
    {
        cin >> n >> m >> Start >> End;

        refresh();

        // inputing graph
        while( m-- )
        {
            long long u, v, c;
            cin >> u >> v >> c;

            graph[u].push_back(v);
            graph[v].push_back(u);

            cost[u].push_back(c);
            cost[v].push_back(c);
        }

        dijkstra();

        // output
        cout << "Case #" << CASE++ << ": ";
        if( d[End] == INF ) cout << "unreachable" << endl;
        else cout << d[End] << endl;
    }

    return 0;
}
