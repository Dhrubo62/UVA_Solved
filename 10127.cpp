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

int dp[10010];
int mod( long long cnt, long long m )
{
    if( !cnt ) return 0;

    if( dp[cnt] != -1 ) return dp[cnt];
    return dp[cnt] = ( ((mod(cnt-1,m) * (10%m)) %m) + (1%m) ) %m;
}

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    long long n;
    while( cin >> n )
    {
        if( !n )
        {
            cout << "0" << endl;
            continue;
        }

        memset( dp, -1, sizeof dp );
        long long cnt = 1;
        while( true )
        {
            if( !mod(cnt,n)) { cout << cnt << endl; break; }
            else cnt++;
        }
    }

    return 0;
}
