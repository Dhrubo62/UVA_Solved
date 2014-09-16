/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 821 - Page Hopping
Catagory: Graph Theory
Method: Floyd-Warshall Algorithm
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

long long INF=pow( 2, 8*sizeof( long long ) - 1 ) - 1;
long long g[100][100];
int MAX;

void floyd_warshall()
{
    for( int k=0; k<MAX; k++ )
    {
        for( int i=0; i<MAX; i++ )
        {
            for( int j=0; j<MAX; j++ )
            {
                if( g[i][k]!=INF && g[k][j]!=INF && g[i][j]>g[i][k]+g[k][j] )
                    g[i][j]=g[i][k]+g[k][j];
            }
        }
    }
}

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int CASE=1;
    string str;
    while( getline(cin,str) )
    {
        for( int i=0; i<100; i++ ) for( int j=0; j<100; j++ )
        {
            if( i==j ) g[i][j]=0;
            else g[i][j]=INF;
        }

        stringstream sin(str);
        int cnt=0;
        MAX=0;
        int u,v;
        while( sin>>u>>v && !(!u && !v) )
        {
            g[u-1][v-1]=1;
            MAX=max(MAX,u);
            MAX=max(MAX,v);
            cnt++;
        }
        if(!cnt) break;

        floyd_warshall();

        long long ttl=0;
        cnt=0;
        for( int i=0; i<MAX; i++ )
        {
            for( int j=0; j<MAX; j++ ) if( g[i][j]!=INF && i!=j )
            {
                ttl += g[i][j];
                cnt++;
            }
        }
        printf( "Case %d: average length between pages = %.3lf clicks\n", CASE++, (ttl*1.0)/(cnt*1.0) );
    }

    return 0;
}
