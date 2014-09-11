/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11518 - Dominos 2
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

int n,m,l,total;
vector <int> list[10010];
bool mark[10010];

void dfs(int x)
{
    mark[x]=true;
    total++;

    for(int i=0; i<list[x].size(); i++)
    {
        int y=list[x][i];
        if(!mark[y]) dfs(y);
    }
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    cin>>n>>m>>l;

        for(int i=1; i<=n; i++) list[i].clear();

        while(m--)
        {
            int x,y;
            cin>>x>>y;
            list[x].push_back(y);
        }

        total=0;
        memset(mark,false,sizeof mark);
        while(l--)
        {
            int x;
            cin>>x;
            if(!mark[x]) dfs(x);
        }

        cout<<total<<endl;
	}

	return 0;
}
