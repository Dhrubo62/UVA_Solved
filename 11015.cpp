/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11015 - 05-2 Rendezvous
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

long long INF=pow( 2, 8*sizeof( long long )-1 )-1;
long long d[22][22];
int n,m;
vector <string> name;

void floyd_warshall()
{
    for( int k=0; k<n; k++ )
    {
        for( int i=0; i<n; i++ )
        {
            for( int j=0; j<n; j++ )
            {
                if( d[i][k]!=INF && d[k][j]!=INF && d[i][j]>d[i][k]+d[k][j] )
                {
                    d[i][j]=d[i][k]+d[k][j];
                }
            }
        }
    }
}

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int CASE=1;
    while( cin>>n>>m && n )
    {
        for( int i=0; i<n; i++ ) for( int j=0; j<n; j++ )
        {
            if( i==j ) d[i][j]=0;
            else d[i][j]=INF;
        }

        name.clear();
        for( int i=0; i<n; i++ ) { string str; cin>>str; name.push_back(str); }

        while( m-- )
        {
            int u,v;
            long long c;
            cin>>u>>v>>c;
            u--; v--;
            d[u][v]=d[v][u]=c;
        }

        floyd_warshall();
        long long mini, ind=0;
        for( int j=0; j<n; j++ )
        {
            long long ttl=0;
            for( int i=0; i<n; i++ ) ttl+=d[i][j];
            if(!j) mini=ttl;
            else if( ttl<mini ) { mini=ttl; ind=j; }
        }

        cout << "Case #" << CASE++ << " : " << name[ind] << endl;
    }

    return 0;
}
