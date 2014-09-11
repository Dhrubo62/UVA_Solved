/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 383 - Shipping Routes
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

struct point
{
    int node,cost;

    point(int x,int y)
    {
        node=x; cost=y;
    }
};

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    cout<<"SHIPPING ROUTES OUTPUT"<<endl<<endl;

    int t,cse=1;
    cin>>t;
    while(t--)
    {
        int M,n,p;
        cin>>M>>n>>p;

        map <string,int> m;
        string name;
        for(int i=0; i<M; i++) { cin>>name; m[name]=i; }

        vector <int> list[35];
        for(int i=0; i<n; i++)
        {
            string u,v;
            cin>>u>>v;

            list[ m[u] ].push_back(m[v]);
            list[ m[v] ].push_back(m[u]);
        }

        cout<<"DATA SET  "<<cse++<<endl<<endl;
        while(p--)
        {
            int Size; cin>>Size;

            string str;
            cin>>str; int Start=m[str];
            cin>>str; int End=m[str];

            queue <point> q;
            map <int,bool> visited;
            int ans=-1;

            q.push(point(Start,0)); visited[Start]=true;
            while(!q.empty())
            {
                point now=q.front(); q.pop();

                int u=now.node;
                if(u==End) { ans=now.cost; break; }

                for(int i=0; i<list[u].size(); i++)
                {
                    int v=list[u][i];
                    if(!visited[v]) { q.push(point(v,now.cost+1)); visited[v]=true; }
                }
            }

            if(ans==-1) cout<<"NO SHIPMENT POSSIBLE"<<endl;
            else cout<<'$'<<Size*ans*100<<endl;
        }
        cout<<endl;
    }

    cout<<"END OF OUTPUT"<<endl;
    return 0;
}
