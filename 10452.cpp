/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 10452 - "Marcus"
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
/*int dx[]={1,-1,0,0}, dy[]={0,0,1,-1};*/ // 4 way movement
/*int dx[]={1,0,-1,0,1,-1,1,-1}, dy[]={0,1,0,-1,1,1,-1,-1};*/ // 8 way movement

using namespace std;

struct stype
{
    int x,y;
    string path;
};

//3 way movement
int dx[]={0,-1,0};
int dy[]={1,0,-1};
string direction[]={"right","forth","left"};

int main()
{
	int t;
	string line="IEHOVA#";

	cin>>t;
	while(t--)
	{
	    //storage
	    int m,n,i,j,x,y;
	    char grid[1010][1010];

	    //input
	    cin>>m>>n;
        for(i=0; i<m; i++)
        {
            cin>>grid[i];
            for(j=0; j<n; j++) if(grid[i][j]=='@') {x=i; y=j;}
        }

        //bfs initialization
        stype push,now;
        queue <stype> q;
        int seq=0;

        //bfs routine
        push.x=x; push.y=y; push.path="";
        q.push(push);
        while(!q.empty())
        {
            now=q.front(); q.pop();

            if(seq==7) break;

            for(i=0; i<3; i++)
            {
                x=now.x+dx[i]; y=now.y+dy[i];
                if(x>=0 && x<m && y>=0 && y<n && grid[x][y]==line[seq])
                {
                    push.x=x; push.y=y;

                    push.path=now.path;
                    if(push.path.size()) push.path+=" ";
                    push.path+=direction[i];

                    q.push(push); seq++;

                    break;
                }
            }
        }

        //output
        cout<<now.path<<endl;
	}

	return 0;
}
