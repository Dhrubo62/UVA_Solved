/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11110 - Equidivisions
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

int n,cnt;
vector <string> grid;
bool visited[110][110];
char peak;

void refresh()
{
    grid.clear();
    memset(visited,false,sizeof visited);
}

void dfs(int x,int y)
{
    cnt++; visited[x][y]=true;
    for(int i=0; i<4; i++)
    {
        int u=x+dx[i], v=y+dy[i];
        if(u>=0 && u<n && v>=0 && v<n && grid[u][v]==peak && !visited[u][v]) dfs(u,v);
    }
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    while(cin>>n && n)
    {
        refresh();

        //base grid construction
        for(int i=0; i<n; i++)
        {
            string str=""; str.resize(n,' ');
            grid.push_back(str);
        }

        //coloring
        getchar();
        for(int i=0; i<n-1; i++)
        {
            string str; getline(cin,str);
            stringstream sin(str);

            int x,y;
            while(sin>>x>>y)
            {
                x--; y--;
                grid[x][y]=i+'0';
            }
        }

        //inspecting
        for(int i=0; i<n; i++) for(int j=0; j<n; j++) if(!visited[i][j])
        {
            peak=grid[i][j];
            cnt=0; dfs(i,j);
            if(cnt!=n) { cout<<"wrong"<<endl; goto escape; }
        }
        cout<<"good"<<endl;
        escape :;
    }

    return 0;
}
