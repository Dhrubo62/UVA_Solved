/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11331 - The Joys of Farming
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

int clr[2010];
int sub[2010][2], n;
int tag[2];
vector <int> graph[2010];
int b,c;

bool dfs(int u, int col) {
    clr[u] = col;
    tag[col]++;

    bool ok=true;
    for( int i=0; i<graph[u].size(); i++ ) {
        int v = graph[u][i];
        if( clr[v] == col ) return false;
        if( clr[v] == -1 ) ok = dfs( v, 1-col );
    }
    return ok;
}

int dp[2010][2010];
bool call( int i, int ttl ) {
    if( i==n ) {
        if( ttl==b || ttl==c ) return true;
        return false;
    }

    if( dp[i][ttl] != -1 ) return dp[i][ttl];
    return dp[i][ttl] = max( call( i+1, ttl+sub[i][0] ), call( i+1, ttl+sub[i][1] ) );
}

int main() {
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int t; cin>>t;
    while( t-- ) {
        int m;
        cin >> b >> c >> m;

        for( int i=1; i<=b+c; i++ ) {
            graph[i].clear();
            clr[i]=-1;
        }
        while( m-- ) {
            int u,v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        // bicoloring with floodfill
        bool ok=true;
        n=0;
        for( int i=1; i<=b+c; i++ ) {
            if(clr[i]==-1) {
                tag[0]=tag[1]=0;

                if( !dfs(i,0) ) {
                    ok=false;
                    cout << "no" << endl;
                    break;
                }

                sub[n][0] = tag[0];
                sub[n++][1] = tag[1];
            }
        }

        if( ok ) {
            memset(dp,-1,sizeof dp);
            if( call(0,0) ) cout << "yes" << endl;
            else cout << "no" << endl;
        }
    }

    return 0;
}
