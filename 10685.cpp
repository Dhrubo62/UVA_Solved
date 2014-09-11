/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 10685 - "Nature"
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

int par[5010],cost[5010],c,r,max_size;
map <string,int> m;

int parent(int x)
{
    if(par[x]!=x) par[x]=parent(par[x]);
    return par[x];
}

int main()
{
    while(cin>>c>>r && !(!c && !r))
    {
        string u,v; m.clear();
        for(int i=0; i<c; i++)
            par[i]=i, cost[i]=1,
            cin>>u, m[u]=i;

        max_size=1;
        for(int i=0; i<r; i++)
        {
            cin>>u>>v;
            int a=m[u],b=m[v];
            if(parent(a)!=parent(b))
            {
                int x=parent(a),y=parent(b);
                par[x]=y;
                cost[y]+=cost[x];
                max_size=max(max_size,cost[y]);
            }
        }

        cout<<max_size<<endl;

    }

    return 0;
}
