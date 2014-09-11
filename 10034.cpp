/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 10034 - Freckles
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

struct node
{
    double x, y;

    node(double a,double b)
    {
        x = a;
        y = b;
    }
};
vector <node> nodeList;

double costOf(node a, node b)
{
    //cout << "cost " << sqrt( pow( a.x-b.x, 2 ) + pow( a.y-b.y, 2 ) ) << endl;
    return sqrt( pow( a.x-b.x, 2 ) + pow( a.y-b.y, 2 ) );
}

struct edge
{
    int u, v;
    double cost;

    edge(int x,int y,double z)
    {
        u = x;
        v = y;
        cost = z;
    }
};
vector <edge> edgeList;

int par[110];
int parent(int x)
{
    if( par[x] != x ) par[x] = parent( par[x] );
    return par[x];
}

int n,NODE;

bool compare(edge a, edge b)
{
    return a.cost < b.cost;
}

double mst()
{
    sort( edgeList.begin(), edgeList.end(), compare );

    NODE = 0;
    double total = 0.0;

    int len = edgeList.size();
    for(int i=0; i<len && NODE!=n-1; i++)
    {
        int u=edgeList[i].u, v=edgeList[i].v;
        double cost=edgeList[i].cost;

        if( parent(u) != parent(v) )
        {
            par[ parent(u) ] = parent(v);
            NODE++;
            total += cost;
        }
    }

    return total;
}

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    bool first = true;
    int t;
    cin >> t;
    while( t-- )
    {
        cin >> n;

        // storing nodes
        nodeList.clear();
        for(int i=0; i<n; i++)
        {
            par[i] = i; // clearing parents

            double x, y;
            cin >> x >> y;
            nodeList.push_back( node( x, y ) );
        }

        // storing edges
        edgeList.clear();
        for(int i=0; i<n-1; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                double cost = costOf( nodeList[i], nodeList[j] );

                edgeList.push_back( edge( i, j, cost ) );
            }
        }

        // output
        if(!first) cout << endl;
        first = false;
        printf("%.2lf\n", mst() );
    }

    return 0;
}
