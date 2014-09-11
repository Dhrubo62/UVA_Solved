/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 10608 - Friends
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

int par[30010],cost[30010];

int parent(int x)
{
    if(par[x]!=x) par[x]=parent(par[x]);
    return par[x];
}

int main()
{
    //freopen("input.txt","r",stdin);

    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;

        for(int i=1; i<=n; i++) par[i]=i, cost[i]=1;

        int max_cost=1;
        while(m--)
        {
            int u,v;
            cin>>u>>v;
            int x=parent(u), y=parent(v);

            if(x!=y)
            {
                par[x]=y;
                cost[y]+=cost[x];
                max_cost=max(cost[y],max_cost);
            }
        }

        cout<<max_cost<<endl;
    }

    return 0;
}
