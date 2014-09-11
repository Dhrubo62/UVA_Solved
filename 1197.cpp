/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 1197 - The Suspects
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

vector <int> list[30010],grp;
bool mark[30010];
int n,m,cnt;

void dfs(int x)
{
    mark[x]=true;
    cnt++;

    for(int i=0; i<list[x].size(); i++)
    {
        int y=list[x][i];
        if(!mark[y]) dfs(y);
    }
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    while(cin>>n>>m && !(!n && !m))
    {
        //refresh
        for(int i=0; i<n; i++) list[i].clear();

        while(m--)
        {
            grp.clear();
            int mem,s;

            cin>>mem;
            while(mem--)
            {
                cin>>s;
                grp.push_back(s);
            }

            for(int i=1; i<grp.size(); i++)
            {
                list[grp[0]].push_back(grp[i]);
                list[grp[i]].push_back(grp[0]);
            }
        }

        cnt=0; memset(mark,false,sizeof mark);
        dfs(0);

        cout<<cnt<<endl;
    }

    return 0;
}
