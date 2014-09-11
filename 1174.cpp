/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 1174 - IP-TV
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

struct edge
{
    int u,v,w;
    edge(int x,int y,int z)
    {
        u=x, v=y, w=z;
    }
};

int par[2010],c,r;
vector <edge> list;
map <string,int> m;

void clean()
{
    list.clear();
    m.clear();
}

int parent(int x)
{
    if(par[x]!=x) par[x]=parent(par[x]);
    return par[x];
}

int comp(edge a,edge b)
{
    return a.w<b.w;
}

int mst()
{
    sort(list.begin(),list.end(),comp);

    int dst=0,node=0;
    for(int i=0; i<r && node!=c-1; i++)
    {
        int u=parent(list[i].u), v=parent(list[i].v);

        if(u!=v)
        {
            par[u]=v;
            node++; dst+=list[i].w;
        }
    }
    return dst;
}

int main()
{
    //freopen("input.txt","r",stdin);

    bool first=true;
    int t;
    cin>>t;
    while(t--)
    {
        clean();

        cin>>c>>r;
        for(int i=1; i<=c; i++) par[i]=i;

        int total=1;
        for(int i=0; i<r; i++)
        {
            int u,v,w;
            string str;

            cin>>str;
            if(m.find(str)==m.end()) m[str]=total++;
            u=m[str];

            cin>>str;
            if(m.find(str)==m.end()) m[str]=total++;
            v=m[str];

            cin>>w;

            list.push_back(edge(u,v,w));
        }

        if(first) first=false;
        else cout<<endl;
        cout<<mst()<<endl;
    }

    return 0;
}
