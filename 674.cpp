/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 674 - Coin Change
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

int coin[] = { 1, 5, 10, 25, 50 };
int make;

int dp[5][7490];
int call( int i, int amount )
{
    if( i == 5 ) return !amount; // base case. all the coins have been used
    if( dp[i][amount] != -1 ) return dp[i][amount]; // already calculated

    // calculate for first time
    int take=0, not_take=0;
    if( amount - coin[i] >= 0 ) take = call( i, amount - coin[i] );
    not_take = call( i+1, amount );
    return dp[i][amount] = take + not_take;
}

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    memset( dp, -1, sizeof dp );

    while( cin >> make )
    {
        cout << call( 0, make ) << endl;
    }

    return 0;
}
