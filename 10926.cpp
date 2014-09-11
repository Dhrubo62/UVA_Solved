/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 10926 - How Many Dependencies?
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

vector <int> list[110];
int n,q,x,y,total;
bool mark[110];

void dfs(int x)
{
    mark[x]=true;

    for(int i=0; i<list[x].size(); i++)
    {
        int y=list[x][i];
        if(!mark[y]) {total++; dfs(y);}
    }
}

int main()
{
    while(cin>>n && n)
    {
        for(x=1; x<=n; x++)
        {
            list[x].clear();

            cin>>q;
            while(q--)
            {
                cin>>y;
                list[x].push_back(y);
            }
        }

        int max_task,max_dependency=-500;
        for(x=1; x<=n; x++)
        {
            memset(mark,false,sizeof mark);
            total=0;
            dfs(x);
            if(total>max_dependency) {max_task=x; max_dependency=total;}
        }

        cout<<max_task<<endl;
    }

    return 0;
}
