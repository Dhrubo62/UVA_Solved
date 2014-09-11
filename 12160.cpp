/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 12160 - Unlock the Lock
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
    int num,cost;
    pack(int x,int y)
    {
        num=x, cost=y;
    }
};

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int l,r,u,CASE=1;
    while(cin>>l>>r>>u && !(!l && !r && !u))
    {
        vector <int> list;
        for(int i=0; i<u; i++) { int num; cin>>num; list.push_back(num); }

        queue <pack> q;
        map <int,bool> visited;
        int ans=-1;

        q.push(pack(l,0)); visited[l]=true;
        while(!q.empty())
        {
            pack now=q.front(); q.pop();
            int n=now.num;
            if(n==r) { ans=now.cost; break; }

            for(int i=0; i<u; i++)
            {
                int v = (n+list[i])%10000;
                if(!visited[v]) { q.push(pack(v,now.cost+1)); visited[v]=true; }
            }
        }

        printf("Case %d: ",CASE++);
        if(ans==-1) cout<<"Permanently Locked"<<endl;
        else cout<<ans<<endl;
    }

    return 0;
}
