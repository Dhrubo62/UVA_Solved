/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 1208 - Oreon
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
//}
using namespace std;

//{ ---------- Movements
/*int dx[]={1,-1,0,0}, dy[]={0,0,1,-1};*/ // 4 way movement
/*int dx[]={1,0,-1,0,1,-1,1,-1}, dy[]={0,1,0,-1,1,1,-1,-1};*/ // 8 way movement
//}

int n,par[30000];
int parent(int x)
{
    if(par[x]!=x) par[x]=parent(par[x]);
    return par[x];
}

struct edge
{
    int u,v,w;
    edge(int x,int y,int z)
    {
        u=x, v=y, w=z;
    }
};
vector <edge> list;

bool compare(edge a,edge b)
{
    return a.w<b.w;
}

vector <edge> out;
void mst()
{
    //refreshing
    for(int i=0; i<n; i++) par[i]=i;
    out.clear();

    //sorting the edge list
    sort(list.begin(),list.end(),compare);

    //tree construction
    for(int i=0; i<list.size() && out.size()!=n-1; i++)
    {
       int u=list[i].u, v=list[i].v, w=list[i].w;

       if(parent(u)!=parent(v))
       {
           par[parent(u)]=parent(v);
           out.push_back(edge(min(u,v),max(u,v),w));
       }
    }
}

bool output_sort(edge a,edge b)
{
    if(a.w==b.w)
    {
        if(a.u==b.u)
        {
            return a.v<b.v;
        }
        else return a.u<b.u;
    }
    else return a.w<b.w;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int t,csn=0;
    cin>>t;
    while(t--)
    {
        //parent clearing
        cin>>n;

        //input edges
        list.clear();
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                int cost;
                char c;

                if(j) cin>>c>>cost;
                else cin>>cost;

                if(cost) list.push_back(edge(i,j,cost));
            }
        }

        mst();

        //output
        sort(out.begin(),out.end(),output_sort);
        cout<<"Case "<<++csn<<":"<<endl;
        for(int i=0; i<out.size(); i++)
        {
            cout << (char)(out[i].u+'A') << "-" << (char)(out[i].v+'A') << " " <<out[i].w<<endl;
        }
    }

    return 0;
}
