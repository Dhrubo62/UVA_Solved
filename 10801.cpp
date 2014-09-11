/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 10801 - Lift Hopping
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

long long INF = pow( 2, ( sizeof (long long) )*8-1 ) - 1;

struct pack
{
    int node, c;
    pack( int x, int y )
    {
        node = x;
        c = y;
    }
    bool operator < ( const pack& obj ) const
    {
        return obj.c < c;
    }
};

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int n, End;
    while( cin >> n >> End )
    {
        long long d[110];
        vector <int> level[ 110 ];
        vector <int> lift[ 10 ];
        vector <int> lift_time;

        // inputing times needed by the lifts
        for(int i=0; i<n; i++)
        {
            int time_needed; cin >> time_needed;
            lift_time.push_back( time_needed );
        }

        // inputing stopages of the lifts
        getchar();
        for(int i=0; i<n; i++)
        {
            string str; getline( cin, str );
            stringstream ss( str );
            int stopage;
            while( ss >> stopage )
            {
                lift[i].push_back( stopage );
                level[ stopage ].push_back( i );
            }
        }

        // dijkstra algorithm
        for( int i=1; i<110; i++ ) d[i] = INF; d[0] = 0;
        priority_queue <pack> q;
        q.push( pack( 0, d[0] ) );
        while( !q.empty() )
        {
            int u = q.top().node; q.pop();
            if( u == End ) break;
            for( int i=0; i<level[u].size(); i++ )
            {
                int lift_to_take = level[u][i];
                for( int j=0; j<lift[ lift_to_take ].size(); j++ )
                {
                    int v = lift[ lift_to_take ][j];
                    int diff = v - u;
                    if( diff <0 ) diff *= -1;

                    int cost = diff*lift_time[ lift_to_take ];
                    if( u ) cost += 60;

                    if( d[v] > d[u] + cost )
                    {
                        d[v] = d[u] + cost;
                        q.push( pack( v, d[v] ) );
                    }
                }
            }
        }

        // output
        if( d[End] == INF ) cout << "IMPOSSIBLE" << endl;
        else cout << d[ End ] << endl;

    }

    return 0;
}
