/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 374 - Big Mod
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

long long n, m;
long long mod( int p )
{
    if( !p ) return 1;

    if( p%2 )
    {
        return ( ( n%m ) * ( mod(p-1)%m ) )%m;
    }
    else
    {
        long long num = mod( p/2 );
        return ( ( num%m ) * ( num%m ) ) % m;
    }
}

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    long long pw;
    while( cin >> n >> pw >> m )
    {
        if ( !n ) cout << 0 << endl;
        else cout << mod( pw ) << endl;
    }

    return 0;
}
