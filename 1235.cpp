/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 1235 - Anti Brute Force Lock
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

struct edge
{
    int u,v,cost;
    edge(int x,int y,int z)
    {
        u=x; v=y; cost=z;
    }
};
vector <edge> edge_list;

int n;

map <string,int> m;
vector <string> node_list;

int edge_cost(string one,string two)
{
    int cost=0;
    for(int i=0; i<4; i++)
    {
        int c = max(one[i],two[i]) - min(one[i],two[i]);
        if(c>5) c = 10 - c;
        cost += c;
    }

    return cost;
}

int par[510];
int parent(int x)
{
    if(par[x]!=x) par[x]=parent(par[x]);
    return par[x];
}

bool compare(edge a,edge b)
{
    return a.cost < b.cost;
}

int mst()
{
   //clearing parents
   for(int i=0; i<n; i++) par[i]=i;

   //sorting list
   sort(edge_list.begin(), edge_list.end(), compare);

   //making tree
   int total=0,connected_nodes=0;
   for(int i=0; i<edge_list.size() && connected_nodes!=n-1; i++)
   {
       int u=edge_list[i].u, v=edge_list[i].v, cost=edge_list[i].cost;

       if( parent(u) != parent(v) )
       {
           par[ parent(u) ] = parent(v);
           connected_nodes++;
           total += cost;
       }
   }

   return total;
}

void refresh()
{
    m.clear();
    node_list.clear();
    edge_list.clear();
}

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int t; cin>>t;
    while(t--)
    {
        refresh();

        cin>>n;

        //storing nodes
        for(int i=0; i<n; i++) { string str; cin>>str; node_list.push_back(str); m[str]=i; }

        //storing edges
        for(int i=0; i<n-1; i++) for(int j=i+1; j<n; j++)
        {
            int cost = edge_cost(node_list[i],node_list[j]);
            edge_list.push_back( edge ( m[ node_list[i] ], m[ node_list[j] ], cost ) );
        }

        //counting the cost of the very first transition
        int very_first=0;
        for(int i=0; i<node_list.size(); i++)
        {
            int cost = edge_cost( "0000", node_list[i] );
            if(!i) very_first = cost;
            else very_first = min( very_first, cost );
        }

        cout<<mst() + very_first<<endl;
    }

    return 0;
}
