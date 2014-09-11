/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11503 - Virtual Friends
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

int par[100010],cost[100010];
map <string,int> m;

int parent(int x)
{
    if(par[x]!=x) par[x]=parent(par[x]);
    return par[x];
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        m.clear();
        string str;
        int a,b,total=0;

        int f;
        cin>>f;
        while(f--)
        {
            cin>>str;
            if(m.find(str)==m.end())
            {
                m[str]=total++, a=m[str];
                par[a]=a; cost[a]=1;
            }
            else a=m[str];

            cin>>str;
            if(m.find(str)==m.end())
            {
                m[str]=total++, b=m[str];
                par[b]=b; cost[b]=1;
            }
            else b=m[str];

            int x=parent(a), y=parent(b);
            if(x!=y)
            {
                par[x]=y;
                cost[y]+=cost[x];
            }
            cout<<cost[y]<<endl;
        }
    }

    return 0;
}
