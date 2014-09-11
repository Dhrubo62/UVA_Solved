/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 10130 - SuperSale
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

int n, cap;
int dp[1001][31];
int weight[1001], cost[1001];

int sack( int i, int w )
{
    if( i == n ) return 0;
    if( dp[i][w]==-1 )
    {
        int take=0, not_take=0;
        if( w + weight[i] <= cap ) take = cost[i] + sack( i+1, w + weight[i] );
        not_take = sack( i+1, w );
        dp[i][w] = max( take, not_take );
    }
    return dp[i][w];
}

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int t;
    cin >> t;
    while( t-- )
    {
        cin >> n;
        for( int i=0; i<n; i++ ) cin >> cost[i] >> weight[i];

        long long ttl = 0;
        int g;
        cin >> g;
        while( g-- )
        {
            cin >> cap;
            memset( dp, -1, sizeof dp );
            ttl += sack( 0, 0 );
        }

        cout << ttl << endl;
    }

    return 0;
}
