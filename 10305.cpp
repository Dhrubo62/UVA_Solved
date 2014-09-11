/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 10305 - Ordering Tasks
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

int indegree[110],n,m;
vector <int> adjacent[110],top;
queue <int> q;

void input_clean()
{
    for(int i=1; i<=n; i++) indegree[i]=0, adjacent[i].clear();
}

void top_clean()
{
    while(!q.empty()) q.pop();
    top.clear();
}

void top_sort()
{
    top_clean();
    for(int i=1; i<=n; i++) if(!indegree[i]) q.push(i);
    while(!q.empty())
    {
        int u=q.front(); q.pop();
        top.push_back(u);
        for(int i=0; i<(int)adjacent[u].size(); i++)
        {
            int v=adjacent[u][i];
            indegree[v]--;
            if(!indegree[v]) q.push(v);
        }
    }
}

int main()
{
    //freopen("input.txt","r",stdin);

    while(cin>>n>>m && !(!n && !m))
    {
        input_clean();
        for(int i=0; i<m; i++)
        {
            int u,v;
            cin>>u>>v;
            adjacent[u].push_back(v);
            indegree[v]++;
        }

        top_sort();
        bool first=true;
        for(int i=0; i<(int)top.size(); i++)
        {
            if(first) first=false;
            else cout<<" ";
            cout<<top[i];
        }
        cout<<endl;
    }

    return 0;
}
