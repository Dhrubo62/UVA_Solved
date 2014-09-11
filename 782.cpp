/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 782 - Contour Painting
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
int r,c,n,sx,sy;
bool visited[100][100];

void refresh()
{
    grid.clear();
    r=0, c=0;
    memset(visited,false,sizeof visited);
}

bool printable_character(char ch)
{
    if(ch=='*') return false;
    if(ch=='#') return false;
    if(ch=='_') return false;
    if(ch==' ') return false;

    return true;
}

bool valid_to_color(int x,int y)
{
    for(int i=0; i<4; i++)
    {
        int u=x+dx[i], v=y+dy[i];
        if(u>=0 && u<r && v>=0 && v<c && printable_character(grid[u][v])) return true;
    }

    return false;
}

void dfs(int x,int y)
{
    if(valid_to_color(x,y)) grid[x][y]='#';

    visited[x][y]=true;

    for(int i=0; i<4; i++)
    {
        int u=x+dx[i], v=y+dy[i];
        if(u>=0 && u<r && v>=0 && v<c && grid[u][v]==' ' && !visited[u][v]) dfs(u,v);
    }
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n; getchar();
    while(n--)
    {
        refresh();

        //input
        while(getline(cin,str))
        {
            grid.push_back(str);

            if(str[0]=='_') break;

            for(int i=0; i<str.size(); i++) if(str[i]=='*')
            {
                sx=r, sy=i;
                grid[sx][sy]=' ';
            }
            c=max(c,(int)str.size());
            r++;
        }
        c++;

        //increasing size
        for(int i=0; i<r; i++) grid[i].resize(c,' ');

        //dfs
        dfs(sx,sy);

        //decreasing size
        for(int i=0; i<r; i++)
        {
            while(grid[i].size())
            {
                int len=grid[i].size();

                if(grid[i][len-1]==' ') grid[i].erase(len-1,1);
                else break;
            }
        }

        //printing grid
        for(int i=0; i<grid.size(); i++) cout<<grid[i]<<endl;
    }

    return 0;
}
