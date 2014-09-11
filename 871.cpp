/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 871 - Counting Cells in a Blob
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
# include <sstream>
//}
using namespace std;

//{ ---------- Movements
/*int dx[]={1,-1,0,0}, dy[]={0,0,1,-1};*/ // 4 way movement
int dx[]={1,0,-1,0,1,-1,1,-1}, dy[]={0,1,0,-1,1,1,-1,-1}; // 8 way movement
//}

vector <string> grid;
string str;
int r,c,cnt;
bool visited[30][30];

void dfs(int p,int q)
{
    visited[p][q] = true;
    cnt++;

    for(int i=0; i<8; i++)
    {
        int x=p+dx[i], y = q + dy[i];

        if(x>=0 && x<r && y>=0 && y<c && grid[x][y]=='1' && !visited[x][y]) dfs(x,y);
    }
}

int main()
{
    //freopen("input.txt","r",stdin);

    bool first=true;
    int t;
    cin >> t; getchar(); getline(cin,str); //clearing the blank line

    while(t--)
    {
        //input
        while(getline(cin,str) && str!="") grid.push_back(str);
        r = grid.size();
        c = grid[0].size();

        int max_cnt=0;
        memset(visited, false, sizeof visited);

        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                if(grid[i][j]=='1' && !visited[i][j])
                {
                    cnt=0;
                    dfs(i,j);
                    max_cnt=max(max_cnt,cnt);
                }
            }
        }

        if(!first) cout<<endl;
        first=false;
        cout<<max_cnt<<endl;

        grid.clear();
    }

    return 0;
}
