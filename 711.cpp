/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 711 - Dividing up
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

long long lim[6];
long long dp[6][60001];
bool call( long long val, long long amount ) {
    if( val==6 ) {
        return !amount;
    }
    if( dp[val][amount] != -1 ) return dp[val][amount];

    bool ok=false;
    for( int i=0; i<=lim[val] && amount-i*(val+1)>=0 && !ok ; i++ ) {
        ok = max( ok, call( val+1, amount-i*(val+1) ) );
    }
    return dp[val][amount] = ok;
}

int main() {
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int CASE = 1;
    while( cin>>lim[0]>>lim[1]>>lim[2]>>lim[3]>>lim[4]>>lim[5] ) {
        long long n=0;
        for( long long i=0; i<6; i++ ) {
            n += (i+1) * lim[i];
        }
        if(!n) break;

        cout << "Collection #" << CASE++ << ":" << endl;
        if( n%2 ) cout << "Can't be divided." << endl<<endl;
        else {
            n/=2;
            memset( dp, -1, sizeof dp );
            if( call(0,n) ) cout << "Can be divided." << endl<<endl;
            else cout << "Can't be divided." << endl<<endl;
        }
    }


    return 0;
}
