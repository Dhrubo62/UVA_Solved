/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11228 - Transportation system.
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
    int u,v;
    double cost;
    edge(int x,int y,double z)
    {
        u=x; v=y; cost=z;
    }
};
vector <edge> edgeList;

struct node
{
    double x,y;
    node(double a,double b)
    {
        x=a; y=b;
    }
};
vector <node> nodeList;

double costOf(node a,node b)
{
    return sqrt( pow( a.x-b.x, 2.0 ) + pow( a.y-b.y, 2.0 ) );
}

int n,CASE;
double r,rail,road;

int par[1010];
int parent(int x)
{
    if(par[x]!=x) par[x] = parent( par[x] );
    return par[x];
}

bool compare(edge a,edge b)
{
    return a.cost < b.cost;
}

void mst()
{
    //clearing parents for the second time
    for(int i=0; i<n; i++) par[i]=i;

    //sorting the edge list and mst initialization
    rail = road = 0.0;
    sort(edgeList.begin(), edgeList.end(), compare);

    //tree construction
    int connectedNodes=0;
    for(int i=0; i<edgeList.size() && connectedNodes!=n-1; i++)
    {
        int u=edgeList[i].u, v=edgeList[i].v;
        double cost=edgeList[i].cost;

        if( parent(u) != parent(v) )
        {
            par[ parent(u) ] = parent(v);

            if(cost <= r) road += cost;
            else rail += cost;

            connectedNodes++;
        }
    }
}

int valueOf(double x)
{
    if( ( x - floor(x) ) < ( ceil(x) - x ) ) return floor(x);
    else return ceil(x);
}

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int t; cin>>t;
    while(t--)
    {
        cin>>n>>r;

        //storing nodes
        nodeList.clear(); //clearing node list
        for(int i=0; i<n; i++)
        {
            double x,y; cin>>x>>y;

            par[i]=i; //clearing parents for the first time
            nodeList.push_back( node(x, y) );
        }

        //storing edges
        int numberOfStates = n;
        edgeList.clear(); //clearing edge list
        for(int i=0; i<n-1; i++) for(int j=i+1; j<n; j++)
        {
            double cost = costOf( nodeList[i], nodeList[j] ); //cost calculation

            if(cost <= r) //then they are in same state. lets join them if they are not joined
            {
                if( parent(i) != parent(j) )
                {
                    par[ parent(i) ] = parent(j);
                    numberOfStates--;
                }
            }

            edgeList.push_back( edge(i,j,cost) );
        }

        //output
        mst();
        printf("Case #%d: %d %d %d\n", ++CASE, numberOfStates, valueOf(road), valueOf(rail));
    }

    return 0;
}
