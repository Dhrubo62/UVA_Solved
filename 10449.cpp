/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 10449 - Traffic
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

long long INF = pow( 2, 8*sizeof(long long)-1 ) -1;

long long d[210],b[210];
int n,m;

struct edge {
    long long u,v,c;
    edge( long long p, long long q, long long r ) {
        u=p;
        v=q;
        c=r;
    }
};
vector <edge> e;
vector <int> g[210];
bool visit[210];
bool cycle;

void dfs( int u ) {
    visit[u] = true;
    for( int i=0; i<g[u].size(); i++ ) {
        int v = g[u][i];
        if( !visit[v] ) dfs(v);
    }
}

void bellmanFord() {
    d[1] = 0;
    memset(visit, false, sizeof visit);
    cycle = false;

    for( int i=0; i<n; i++ ) {
        for( int j=0; j<m; j++ ) {
            long long u=e[j].u;
            long long v=e[j].v;
            long long c=e[j].c;

            if( d[u]!=INF && d[u]+c<d[v] ) {
                d[v] = d[u] + c;

                if( i==n-1 ) {
                    cycle = true;
                    if( !visit[u] ) dfs(u);
                }
            }
        }
    }
}

int main() {
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int CASE = 0;
    while( cin >> n ) {
        for( int i=1; i<=n; i++ ) {
            cin >> b[i];
            d[i] = INF;
            g[i].clear();
        }

        e.clear();
        cin >> m;
        for( int i=0; i<m; i++ ) {
            int u,v;
            cin >> u >> v;
            e.push_back( edge( u, v, (b[v]-b[u])*(b[v]-b[u])*(b[v]-b[u]) ) );
            g[u].push_back(v);
        }

        cout << "Set #" << ++CASE << endl;
        bellmanFord();
        int q;
        cin >> q;
        while( q-- ) {
            int node; cin >> node;

            if( cycle && visit[node] ) cout << "?" << endl;
            else if( d[node]<3 || d[node]==INF ) cout << "?" << endl;
            else cout << d[node] << endl;
        }
    }


    return 0;
}
