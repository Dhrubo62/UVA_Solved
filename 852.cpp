/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 852 - Deciding victory in Go
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
bool mark[10][10];
int w,b;

bool ok;
char peak;
int cnt;

void dfs(int x,int y)
{
    if(grid[x][y]!='.')
    {
        if(ok)
        {
            if(peak=='A') peak=grid[x][y];
            else if(peak!=grid[x][y]) ok=false;
        }
    }
    else
    {
        mark[x][y]=true;
        cnt++;

        for(int i=0; i<4; i++)
        {
            int u=x+dx[i], v=y+dy[i];

            if(u>=0 && u<9 && v>=0 && v<9 && !mark[u][v]) dfs(u,v);
        }
    }
}

bool surrounded(int x,int y,char ch)
{
    int free_point=0;
    for(int i=0; i<4; i++)
    {
        int u=x+dx[i], v=y+dy[i];

        if(u>=0 && u<9 && v>=0 && v<9 && (grid[u][v]=='.' || grid[u][v]==ch)) free_point++;
    }

    return !free_point;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int t;
    cin>>t;

    while(t--)
    {
        grid.clear();
        w=b=0;

        for(int i=0; i<9; i++)
        {
            string str;
            cin>>str;

            grid.push_back(str);
        }

        //stone counting and removing
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                if(grid[i][j]=='O')
                {
                    if(surrounded(i,j,'O')) grid[i][j]='.';
                    else w++;
                }
                else if(grid[i][j]=='X')
                {
                    if(surrounded(i,j,'X')) grid[i][j]='.';
                    else b++;
                }
            }
        }

        //empty position counting
        memset(mark,false,sizeof mark);
        for(int i=0; i<9; i++) for(int j=0; j<9; j++) if(grid[i][j]=='.' && !mark[i][j])
        {
            ok=true; peak='A';
            cnt=0;

            dfs(i,j);

            if(ok)
            {
                if(peak=='O') w+=cnt;
                else if(peak=='X') b+=cnt;
            }
        }

        cout<<"Black "<<b<<" White "<<w<<endl;
    }

    return 0;
}
