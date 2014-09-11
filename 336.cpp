/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 336 - A Node Too Far
*/

// ----------------- C headers
# include <cstdio>
# include <cstring>
# include <cmath>
# include <cstdlib>
# include <cctype>

// ----------------- C++ headers
# include <iostream>
# include <string>
# include <algorithm>
# include <vector>
# include <queue>
# include <map>

using namespace std;

//------------------ Movements
/*int dx[]={1,-1,0,0}, dy[]={0,0,1,-1};*/ // 4 way movement
/*int dx[]={1,0,-1,0,1,-1,1,-1}, dy[]={0,1,0,-1,1,1,-1,-1};*/ // 8 way movement

struct stype
{
    int node,ttl;
};

int main()
{
    int n,t=0;
    while(cin>>n && n)
    {
        vector <int> list[50];
        int i,x,y,node,total_node=0,ttl,visited;
        bool mark[50];
        map <int,int> m;

        for(i=0; i<n; i++)
        {
            cin>>node;
            if(m.find(node)==m.end()) m[node]=total_node++;
            x=m[node];

            cin>>node;
            if(m.find(node)==m.end()) m[node]=total_node++;
            y=m[node];

            list[x].push_back(y); list[y].push_back(x);
        }

        while(cin>>node>>ttl && !(!node && !ttl))
        {
            int ini_node=node,ini_ttl=ttl;

            queue <stype> q;
            stype push,now;
            memset(mark,false,sizeof mark);
            visited=0;

            push.node=m[node]; push.ttl=ttl;
            q.push(push); mark[m[node]]=true;
            while(!q.empty())
            {
                now=q.front(); q.pop();
                visited++;

                node=now.node; ttl=now.ttl;
                if(ttl) for(i=0; i<list[node].size(); i++)
                {
                    int destination=list[node][i];
                    if(!mark[destination])
                    {
                        push.node=destination; push.ttl=ttl-1;
                        q.push(push); mark[destination]=true;
                    }
                }
            }

            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",++t,total_node-visited,ini_node,ini_ttl);
        }
    }

    return 0;
}
