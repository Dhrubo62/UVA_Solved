/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 784 - Maze Exploration
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
int dx[]={1,-1,0,0}, dy[]={0,0,1,-1}; // 4 way movement
/*int dx[]={1,0,-1,0,1,-1,1,-1}, dy[]={0,1,0,-1,1,1,-1,-1};*/ // 8 way movement
//}

vector <string> grid;
string str;
int sx,sy,r;

void dfs(int x,int y)
{
    grid[x][y]='#';

    for(int i=0; i<4; i++)
    {
        int u=x+dx[i], v=y+dy[i];

        if(u>=0 && u<r && v>=0 && v<grid[u].size() && grid[u][v]==' ') dfs(u,v);
    }
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int t;
    cin>>t; getchar();
    while(t--)
    {
        r=0; grid.clear();
        while(1)
        {
            getline(cin,str);
            grid.push_back(str);

            for(int i=0; i<str.size(); i++) if(str[i]=='*') sx=r, sy=i;

            if(str[0]=='_') break;
            r++;
        }

        dfs(sx,sy);

        for(int i=0; i<grid.size(); i++) cout<<grid[i]<<endl;
    }

    return 0;
}
