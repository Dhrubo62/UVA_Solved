/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 10009 - All Roads Lead Where?
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

int m,n,c;
map <string,int> val;
map <int,string> name;
string str;
vector <int> adjcnt[30000];

struct edge
{
    int node;
    string cost;

    edge(int x,string y)
    {
        node=x;
        cost=y;
    }
};

queue <edge> q;
bool mark[30000];

string bfs(int src,int desti)
{
    while(!q.empty()) q.pop();
    memset(mark,false,sizeof mark);

    str=""; str+=name[src][0];

    q.push(edge(src,str)); mark[src]=true;

    while(!q.empty())
    {
        edge now=q.front(); q.pop();

        int u=now.node;
        if(u==desti) return now.cost;

        for(int i=0; i<adjcnt[u].size(); i++)
        {
            int v=adjcnt[u][i];

            if(!mark[v])
            {
                q.push(edge(v,now.cost+name[v][0]));
                mark[v]=true;
            }
        }
    }
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    bool first=true;
    int t;

    cin>>t;

    while(t--)
    {
        cin>>m>>n;

        //refresh
        val.clear(); name.clear();
        c=0;

        //input
        while(m--)
        {
            cin>>str;
            if(val.find(str)==val.end())
            {
                val[str]=c;
                name[c]=str;
                adjcnt[c].clear();
                c++;
            }
            int u=val[str];

            cin>>str;
            if(val.find(str)==val.end())
            {
                val[str]=c;
                name[c]=str;
                adjcnt[c].clear();
                c++;
            }
            int v=val[str];

            adjcnt[u].push_back(v);
            adjcnt[v].push_back(u);
        }

        if(!first) cout<<endl;
        first=false;
        while(n--)
        {
            cin>>str; int u=val[str];
            cin>>str; int v=val[str];

            cout<<bfs(u,v)<<endl;
        }
    }

    return 0;
}
