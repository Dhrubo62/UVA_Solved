/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 929 - Number Maze
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
int dx[]={1,-1,0,0}, dy[]={0,0,1,-1}; // 4 way movement
/*int dx[]={1,0,-1,0,1,-1,1,-1}, dy[]={0,1,0,-1,1,1,-1,-1};*/ // 8 way movement
//}

struct pack
{
    int x, y, cost;

    pack( int u, int v, int w )
    {
        x = u;
        y = v;
        cost = w;
    }

    bool operator < ( const pack& obj ) const
    {
        return obj.cost < cost;
    }
};

int n, m;
vector <int> grid[1010];
int d[1010][1010];
int INF = pow( 2, 31 ) - 1;

void grid_refresh()
{
    for(int i=0; i<n; i++) grid[i].clear();
}

void cost_refresh()
{
    for(int i=0; i<n; i++) for(int j=0; j<m; j++) d[i][j] = INF;
}

void dijkstra()
{
    cost_refresh();
    d[0][0] = grid[0][0];

    // algorithm
    priority_queue <pack> q;
    q.push( pack( 0, 0, d[0][0] ) );
    while( !q.empty() )
    {
        int x = q.top().x;
        int y = q.top().y;
        q.pop();

        if( x == n-1 && y == m-1 ) break;

        for(int i=0; i<4; i++)
        {
            int u = x + dx[i];
            int v = y + dy[i];

            if( u>=0 && u<n && v>=0 && v<m )
            {
                if( d[u][v] > d[x][y] + grid[u][v] )
                {
                    d[u][v] = d[x][y] + grid[u][v];
                    q.push( pack( u, v, d[u][v] ) );
                }
            }
        }
    }
}

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int t; cin >> t;
    while( t-- )
    {
        cin >> n >> m;

        // inputing graph
        grid_refresh();
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                int num; cin >> num;
                grid[i].push_back(num);
            }
        }

        dijkstra();

        cout << d[n-1][m-1] << endl;
    }

    return 0;
}
