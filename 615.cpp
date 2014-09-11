/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 615 - Is It A Tree?
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

int n,CASE;

struct edge
{
    int u,v;

    edge(int x,int y)
    {
        u=x; v=y;
    }
};
queue <edge> list;

map <int,bool> appear;
map <int,int> ind,roll;

void refresh()
{
    n=0;
    while(!list.empty()) list.pop();
    appear.clear();
    ind.clear();
    roll.clear();
}

void process_node(int u)
{
    if(!appear[u])
    {
        appear[u]=true;
        roll[u]=n++;
    }
}

int par[30000];
int parent(int x)
{
    if(par[x]!=x) par[x]=parent(par[x]);
    return par[x];
}

bool tree()
{
    //checking for only one root and only one edge towards each node
    int root=0;
    for(int i=0; i<n; i++)
    {
        if(!ind[i]) root++;
        else if(ind[i]>1) return false;
    }
    if(root!=1) return false;

    //checking unique sequence
    for(int i=0; i<n; i++) par[i]=i;

    while(!list.empty())
    {
        edge now=list.front(); list.pop();

        int u=now.u, v=now.v;

        if(parent(u)==parent(v)) return false;
        else par[parent(u)]=parent(v);
    }

    return true;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int u,v;

    while(cin>>u>>v && !(u<0 && v<0))
    {
        refresh();

        while(u && v)
        {
            process_node(u); u=roll[u];
            process_node(v); v=roll[v];

            list.push(edge(u,v));
            ind[v]++;

            cin>>u>>v;
        }

        CASE++;
        if(!n || tree()) cout<<"Case "<<CASE<<" is a tree."<<endl;
        else cout<<"Case "<<CASE<<" is not a tree."<<endl;
    }

    return 0;
}
