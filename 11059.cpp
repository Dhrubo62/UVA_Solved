/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11059 - Maximum Product
Catagory: Adhoc
Method: Adhoc
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

int n;
int val[18];

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int CASE=1;
    while( cin>>n )
    {
        for( int i=0; i<n; i++ ) cin>>val[i];

        long long MAX=0;
        for( int i=0; i<n; i++ )
        {
            for( int j=i; j<n; j++ )
            {
                long long mul=1;
                for( int k=i; k<=j; k++ ) mul *= val[k];
                MAX = max( MAX, mul );
            }
        }

        printf( "Case #%d: The maximum product is %lld.\n\n", CASE++, MAX );
    }

    return 0;
}
