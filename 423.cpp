/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 423 - MPI Maelstrom
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

/*
            a graph was constructed with adjacency list for running dfs.
            but it wasn't done as not being necessary.
*/

int n;
vector <int> g[110];

struct edge {
    long long u,v,c;
    edge( long long a, long long b, long long x ) {
        u = a;
        v = b;
        c = x;
    }
};
vector <edge> e;

long long INF = pow( 2, 8*sizeof(long long)-1 ) -1;
long long d[210];
void bellmanFord() {
    d[1] = 0;
    int m=e.size();

    for( int i=0; i<n-1; i++ ) {
        for( int j=0; j<m; j++ ) {
            int u=e[j].u;
            int v=e[j].v;
            int c=e[j].c;

            if( d[u]!=INF && d[u]+c<d[v] ) {
                d[v] = d[u] + c;
            }
        }
    }
}

int main() {
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    cin >> n;
    for( int i=2; i<=n; i++ ) {

        d[i] = INF;

        for( int j=1; j<=i-1; j++ ) {
            char str[100]; cin >> str;
            if( str[0]!='x' ) {
                long long cost = atol(str);

                g[i].push_back(j);
                g[j].push_back(i);

                e.push_back( edge( i, j, cost ) );
                e.push_back( edge( j, i, cost ) );
            }
        }
    }

    bellmanFord();
    long long MAX=d[1];
    for( int i=2; i<=n; i++ ) {
        MAX = max( MAX, d[i] );
    }
    cout << MAX << endl;

    return 0;
}
