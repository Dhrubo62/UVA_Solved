/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 567 - "Risk"
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

struct container
{
    int country,cost;
};

int main()
{
	int x,n,y,i,csn=0;

	while(cin>>n)
	{
	    //storage
	    vector <int> list[30];

	    //inputing the first line
	    for(i=0; i<n; i++) {cin>>y; list[1].push_back(y); list[y].push_back(1);}

	    //inputing the other 18 lines
	    for(x=2; x<=19; x++)
	    {
	        cin>>n;
	        for(i=0; i<n; i++) {cin>>y; list[x].push_back(y); list[y].push_back(x);}
	    }

	    //inputing queries and processing result with bfs
	    cin>>n;
	    printf("Test Set #%d\n",++csn);
	    while(n--)
	    {
	        int fx,fy;
	        cin>>fx>>fy;

	        //bfs initialization
	        container push,now;
	        queue <container> q;
	        bool mark[30]; memset(mark,false,sizeof mark);
	        int ans;

	        //bfs routine
	        push.country=fx; push.cost=0;
	        q.push(push); mark[fx]=true;
	        while(!q.empty())
	        {
	            now=q.front(); q.pop();

	            x=now.country;
	            if(x==fy) {ans=now.cost; break;}

	            for(i=0; i<list[x].size(); i++)
	            {
	                y=list[x][i];
	                if(!mark[y])
	                {
	                    push.country=y; push.cost=now.cost+1;
	                    q.push(push); mark[y]=true;
	                }
	            }
	        }

	        printf("%2d to %2d: %d\n",fx,fy,ans);
	    }
	    cout<<endl;
	}

	return 0;
}
