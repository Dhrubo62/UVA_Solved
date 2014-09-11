/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11137 - Ingenuous Cubrency
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

long long dp[22][10001];
long long call( long long coin, long long amount )
{
    if( coin == 22 ) return amount == 0;
    if( dp[coin][amount] != -1 ) return dp[coin][amount];

    long long take=0, not_take=0;
    if( amount-coin*coin*coin >=0 ) take = call( coin, amount-coin*coin*coin );
    not_take = call( coin+1, amount );

    return dp[coin][amount] = take + not_take;
}

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    memset( dp, -1, sizeof dp );
    long long amount;
    while( cin >> amount )
    {
        cout << call( 1, amount ) << endl;
    }

    return 0;
}
