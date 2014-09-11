/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11974 - Switch The Lights
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

struct pack
{
    int state,cost;
    pack(int x,int y)
    {
        state=x; cost=y;
    }
};

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int CASE=1,t; cin>>t;
    while(t--)
    {
        int n,m; cin>>n>>m;
        int start=(int)pow(2,n) - 1;

        vector <int> s;
        for(int i=0; i<m; i++)
        {
            int num=0;
            for(int j=0; j<n; j++)
            {
                int p; cin>>p;
                num+=(int) pow(2,j) * p;
            }
            if(num) s.push_back(num);
        }

        queue <pack> q;
        map <int,bool> visited;
        int ans=-1;

        q.push(pack(start,0)); visited[start]=true;
        while(!q.empty())
        {
            pack now=q.front(); q.pop();

            int num=now.state;
            if(!num) { ans=now.cost; break; }

            for(int i=0; i<s.size(); i++)
            {
                int v=s[i],u=num;
                u = u ^ v;
                if(!visited[u]) { q.push(pack(u,now.cost+1)); visited[u]=true; }
            }
        }

        printf("Case %d: ",CASE++);
        if(ans==-1) cout<<"IMPOSSIBLE"<<endl;
        else cout<<ans<<endl;
    }

    return 0;
}
