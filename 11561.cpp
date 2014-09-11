/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11561 - Getting Gold
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
bool risk[60][60];
string str;
int r,c,sx,sy,cnt;

void dfs(int x,int y)
{
    if(grid[x][y]=='G') cnt++;
    grid[x][y]='#';

    if(!risk[x][y])
    {
        for(int i=0; i<4; i++)
        {
            int u=x+dx[i], v=y+dy[i];

            if(u>=0 && u<r && v>=0 && v<c && grid[u][v]!='#' && grid[u][v]!='T') dfs(u,v);
        }
    }
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    while(cin>>c>>r)
    {
        //refresh
        grid.clear();
        memset(risk,false,sizeof risk);

        //input
        for(int i=0; i<r; i++)
        {
            cin>>str;
            for(int j=0; j<c; j++) if(str[j]=='P') sx=i, sy=j;

            grid.push_back(str);
        }

        //risk marking
        for(int i=0; i<r; i++) for(int j=0; j<c; j++) if(grid[i][j]=='T')
        {
            for(int k=0; k<4; k++)
            {
                int u=i+dx[k], v=j+dy[k];
                if(u>=0 & u<r && v>=0 && v<c) risk[u][v]=true;
            }
        }

        //counting
        cnt=0;
        dfs(sx,sy);

        //result
        cout<<cnt<<endl;
    }

    return 0;
}
