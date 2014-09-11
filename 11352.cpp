/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11352 - Crazy King
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
int dx[]={1,0,-1,0,1,-1,1,-1}, dy[]={0,1,0,-1,1,1,-1,-1}; // 8 way movement
//}

int dxZ[]={2,1,-2,-1,2,1,-2,-1};
int dyZ[]={1,2,1,2,-1,-2,-1,-2};

int m,n;
bool inGrid(int x,int y)
{
    if(x<0) return false;
    else if(y<0) return false;
    else if(x>=m) return false;
    else if(y>=n) return false;
    else return true;
}

struct pack
{
    int x,y,cost;
    pack(int a,int b,int c)
    {
        x=a; y=b; cost=c;
    }
};

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int t; cin>>t;
    while(t--)
    {
        cin>>m>>n;

        int X,Y,U,V;
        string str;
        vector <string> grid;
        for(int i=0; i<m; i++) { cin>>str; grid.push_back(str); }

        for(int i=0; i<m; i++) for(int j=0; j<n; j++)
        {
            if(grid[i][j]=='Z')
            {
                for(int k=0; k<8; k++)
                {
                    int x=i+dxZ[k], y=j+dyZ[k];
                    if(inGrid(x,y) && grid[x][y]=='.') grid[x][y]='X';
                }
            }
            else if(grid[i][j]=='A') { X=i; Y=j; }
            else if(grid[i][j]=='B') { U=i; V=j; }
        }

        int ans=-1;
        queue <pack> q;
        q.push(pack(X,Y,0)); grid[X][Y]='Z';
        while(!q.empty())
        {
            pack now=q.front(); q.pop();
            int x=now.x, y=now.y;
            if(x==U && y==V) { ans=now.cost; break; }

            for(int i=0; i<8; i++)
            {
                int u=x+dx[i], v=y+dy[i];
                if(inGrid(u,v) && grid[u][v]!='Z' && grid[u][v]!='X') { q.push(pack(u,v,now.cost+1)); grid[u][v]='Z'; }
            }
        }

        if(ans==-1) cout<<"King Peter, you can't go now!"<<endl;
        else printf("Minimal possible length of a trip is %d\n",ans);
    }

    return 0;
}
