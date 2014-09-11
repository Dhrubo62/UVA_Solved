/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 352 - "The Seasonal War"
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

//------------------ Movements
/*int dx[]={1,-1,0,0}; // 4 way movement
int dy[]={0,0,1,-1};*/

int dx[]={1,0,-1,0,1,-1,1,-1}; // 8 way movement
int dy[]={0,1,0,-1,1,1,-1,-1};

using namespace std;

struct stype
{
    int x,y;
};

int main()
{
	int csn=0,n;

	while(cin>>n)
	{
	    //input
	    char grid[35][35];
	    int i;
	    for(i=0; i<n; i++) cin>>grid[i];

	    //checking
	    int eagle=0,j,k;
	    bool mark[35][35]; memset(mark,false,sizeof mark);
	    for(i=0; i<n; i++) for(j=0; j<n; j++) if(grid[i][j]=='1' && !mark[i][j])
	    {
	        eagle++;

	        //bfs initialization
	        stype now,push;
	        queue <stype> q;
	        int x,y;

	        //bfs routine
	        push.x=i; push.y=j;
	        q.push(push); mark[i][j]=true;
	        while(!q.empty())
	        {
	            now=q.front(); q.pop();

	            for(k=0; k<8; k++)
	            {
	                x=now.x+dx[k]; y=now.y+dy[k];
	                if(x>=0 && x<n && y>=0 && y<n && grid[x][y]=='1' && !mark[x][y])
	                {
	                    push.x=x; push.y=y;
	                    q.push(push); mark[x][y]=true;
	                }
	            }
	        }
	    }

	    printf("Image number %d contains %d war eagles.\n",++csn,eagle);
	}

	return 0;
}
