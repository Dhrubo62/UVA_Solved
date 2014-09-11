/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 10583 - Ubiquitous Religions
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
# include <map>
//}
using namespace std;

//{ ---------- Movements
/*int dx[]={1,-1,0,0}, dy[]={0,0,1,-1};*/ // 4 way movement
/*int dx[]={1,0,-1,0,1,-1,1,-1}, dy[]={0,1,0,-1,1,1,-1,-1};*/ // 8 way movement
//}

int par[50010],t;

int parent(int x)
{
    if(par[x]!=x) par[x]=parent(par[x]);
    return par[x];
}

int main()
{
    int n,m;
    while(cin>>n>>m && !(!n && !m))
    {
        for(int i=1; i<=n; i++) par[i]=i;

        while(m--)
        {
            int u,v;
            cin>>u>>v;
            if(parent(u)!=parent(v))
            {
                n--;
                par[parent(u)]=parent(v);
            }
        }

        printf("Case %d: %d\n",++t,n);
    }

    return 0;
}
