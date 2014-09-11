/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 10959 - The Party, Part I
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

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    bool first = true;
    int t;
    cin >> t;
    while( t-- )
    {
        int n, m;
        cin >> n >> m;

        vector <int> graph[1010];
        while( m-- )
        {
            int u, v;
            cin >> u >> v;

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        int num[1010]; memset( num, -1, sizeof num );
        queue <int> q;

        q.push(0); num[0] = 0;
        while(!q.empty())
        {
            int u = q.front(); q.pop();

            for(int i=0; i<graph[u].size(); i++)
            {
                int v = graph[u][i];

                if( num[v] == -1 )
                {
                    q.push(v);
                    num[v] = num[u] + 1;
                }
            }
        }

        if(!first) cout << endl;
        first = false;
        for(int i=1; i<n; i++) cout << num[i] << endl;
    }

    return 0;
}
