/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 785 - Grid Colouring
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
int dx[]={1,-1,0,0}, dy[]={0,0,1,-1}; // 4 way movement
/*int dx[]={1,0,-1,0,1,-1,1,-1}, dy[]={0,1,0,-1,1,1,-1,-1};*/ // 8 way movement
//}

vector <string> grid;
string str;
int n,len;
char color;

void dfs(int x,int y)
{
    grid[x][y]=color;
    for(int i=0; i<4; i++)
    {
        int p=x+dx[i], q=y+dy[i];
        if(p>=0 && p<n && q>=0 && q<grid[p].size() && grid[p][q]==' ') dfs(p,q);
    }
}

int main()
{
    //freopen("input.txt","r",stdin);

    start:
    while(getline(cin,str))
    {
        grid.push_back(str);
        if(str[0]=='_')break;
    }

    if(!grid.size()) return 0;

    n=grid.size()-1;
    for(int i=0; i<n; i++)
    {
        len=grid[i].size();
        for(int j=0; j<len; j++) if(grid[i][j]!='X' && grid[i][j]!=' ')
        {
            color=grid[i][j];
            dfs(i,j);
        }
    }

    for(int i=0; i<n+1; i++) cout<<grid[i]<<endl;
    grid.clear();
    goto start;
}
