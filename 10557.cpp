/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 10557 - XYZZY
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

struct edge {
    int u,v;
    edge( int a, int b ) {
        u=a; v=b;
    }
};

vector <int> adjacent[110];
bool visit[110];

void dfs(int u) {
    visit[u]=true;
    for( int i=0; i<adjacent[u].size(); i++ ) {
        int v = adjacent[u][i];
        if( !visit[v] ) dfs(v);
    }
}

int main() {
//   freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int n;
    while( cin>>n && n!=-1 ) {
        // input
        vector <long long> energy;
        vector <edge> list;
        for( int i=0; i<n; i++ ) {
            int e; cin >> e;
            energy.push_back(e);

            int r; cin >> r;
            adjacent[i].clear();
            while( r-- ) {
                int j; cin >> j;
                list.push_back( edge( i, j-1 ) );
                adjacent[i].push_back(j-1);
            }
        }

        // dfs
        /*memset(visit, false, sizeof visit);
        dfs(0);
        if( !visit[n-1] ) {
            cout << "hopeless" << endl;
            continue;
        }*/

        // bellman-ford
        vector <long long> d(n,0);
        d[0] = 100;
        int cycle=-1;
        int m=list.size();
        // algorithm
        for( int i=0; i<n; i++ ) {
            cycle = -1;
            for( int j=0; j<m; j++ ) {
                int u=list[j].u;
                int v=list[j].v;
                int c=energy[v];

                if( d[u] && d[u]+c>d[v] ) {
                    d[v] = d[u]+c;
                    cycle = u;
                }
            }
        }
        // output
        if( cycle!=-1 ) {
            memset(visit, false, sizeof visit);
            dfs(cycle);
            if( visit[n-1] ) cout << "winnable" << endl;
            else cout << "hopeless" << endl;
        }
        else if( d[n-1] ) cout << "winnable" << endl;
        else cout << "hopeless" << endl;
    }

    return 0;
}
