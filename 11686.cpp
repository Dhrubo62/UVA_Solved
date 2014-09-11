/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11686 - Pick up sticks
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

int indegree[1000010],n,m,node;
vector <int> adjacent[1000010],top;
queue <int> q;

void main_clean()
{
    for(int i=1; i<=n; i++) indegree[i]=0, adjacent[i].clear();
}

void top_clean()
{
    top.clear();
    node=0;
    while(!q.empty()) q.pop();
}

void top_sort()
{
    top_clean();

    for(int i=1; i<=n; i++) if(!indegree[i]) q.push(i), node++;

    while(!q.empty())
    {
        int u=q.front(); q.pop();
        top.push_back(u);

        for(int i=0; i<adjacent[u].size(); i++)
        {
            int v=adjacent[u][i];
            indegree[v]--;
            if(!indegree[v]) q.push(v), node++;
        }
    }
}

int main()
{
    //freopen("input.txt","r",stdin);

    while(cin>>n>>m && !(!n && !m))
    {
        main_clean();
        while(m--)
        {
            int u,v;
            cin>>u>>v;
            adjacent[u].push_back(v);
            indegree[v]++;
        }

        top_sort();
        if(node==n) for(int i=0; i<top.size(); i++) cout<<top[i]<<endl;
        else cout<<"IMPOSSIBLE"<<endl;
    }

    return 0;
}
