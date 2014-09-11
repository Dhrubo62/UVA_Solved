/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 469 - "Wetlands of Florida"
*/

# include <iostream>
# include <cstdio>
# include <cstring>
# include <string>
# include <cmath>
# include <cstdlib>
# include <algorithm>
# include <cctype>
# include <vector>
# include <queue>

using namespace std;

int dx[]={1,-1,0,0,1,-1,1,-1};
int dy[]={0,0,1,-1,1,1,-1,-1};

struct stype
{
    int x,y;
};

int main()
{
	int t,r,c,x,y,i,j,len,cnt;
	bool first=true;
    string grid[110];
    char str[110];

	cin>>t;
	getchar();
	gets(str); //input the blank line
	while(t)
	{
	    t--;
	    r=0;

	    if(first) first=false;
	    else cout<<endl;

	    bool marked[110][110];
	    int cost[110][110]; memset(cost,-1,sizeof cost);
	    r=0;

	    while(gets(str))
	    {
	        if(!strlen(str)) break;
	        else if(str[0]=='L' || str[0]=='W')
	        {
	            grid[r++]=str;
	            c=strlen(str);
	        }
	        else
	        {
	            x=0; y=0; i=0;
	            len=strlen(str);

	            //evaluate x
	            while(str[i]>='0' && str[i]<='9') x=x*10+str[i++]-'0';

	            //passing spaces
	            while(str[i]==' ') i++;

	            //evaluate y
	            while(i<len) y=y*10+str[i++]-'0';

	            x--; y--;
	            if(cost[x][y]!=-1) cout<<cost[x][y]<<endl;
	            else
	            {
	                //initializing bfs
	                queue <stype> q;
	                stype push,now;
	                cnt=0;
	                memset(marked,0,sizeof marked);

	                //bfs routine
	                push.x=x; push.y=y;
	                q.push(push); marked[x][y]=true;
	                while(!q.empty())
	                {
	                    now=q.front(); q.pop();

	                    if(grid[now.x][now.y]=='W') cnt++;

	                    for(i=0; i<8; i++)
	                    {
	                        x=now.x+dx[i]; y=now.y+dy[i];
	                        if(x>=0 && x<r && y>=0 && y<c && grid[x][y]=='W' && !marked[x][y])
	                        {
	                            push.x=x; push.y=y;
	                            q.push(push); marked[x][y]=true;
	                        }
	                    }
	                }

	                //result process
	                for(i=0; i<r; i++) for(j=0; j<c; j++) if(marked[i][j]) cost[i][j]=cnt;
	                cout<<cnt<<endl;
	            }
	        }
	    }
	}

	return 0;
}
