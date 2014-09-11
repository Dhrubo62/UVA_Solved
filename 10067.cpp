/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 10067 - Playing with Wheels
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
# include <map>

using namespace std;

//------------------ Movements
/*int dx[]={1,-1,0,0}, dy[]={0,0,1,-1};*/ // 4 way movement
/*int dx[]={1,0,-1,0,1,-1,1,-1}, dy[]={0,1,0,-1,1,1,-1,-1};*/ // 8 way movement

struct stype
{
    string word;
    int cost;
};

char left(char x)
{
    return x=='0' ? '9': --x;
}

char right(char x)
{
    return x=='9' ? '0': ++x;
}

int main()
{
	int t,q;
	cin>>t;
	while(t--)
	{
	    string start,end,str,temp;
        map <string,bool> forbidden;
        int i,j;

	    //input
	    start="";
	    for(i=0; i<4; i++) {cin>>temp; start+=temp;}
	    end="";
	    for(i=0; i<4; i++) {cin>>temp; end+=temp;}
	    cin>>q;
	    while(q--)
	    {
	        str="";
	        for(i=0; i<4; i++) {cin>>temp; str+=temp;}
	        forbidden[str]=true;
        }

	    //bfs initialization
	    map <string,bool> visited;
	    queue <stype> q;
	    stype push,now;
	    int ans=-1;

	    //escape
	    if(forbidden[start] || forbidden[end]) {cout<<-1<<endl; continue;}

	    //bfs process
	    push.word=start; push.cost=0;
	    q.push(push); visited[start]=true;
	    while(!q.empty())
	    {
	        now=q.front(); q.pop();

	        if(now.word==end) {ans=now.cost; break;}

	        for(i=0; i<2; i++) for(j=0; j<4; j++)
	        {
	            str=now.word;
	            str[j] = i ? left(str[j]): right(str[j]);

	            if(forbidden[str] || visited[str]) continue;

	            push.word=str; push.cost=now.cost+1;
	            q.push(push); visited[str]=true;
	        }
	    }

	    //output
	    cout<<ans<<endl;
	}

	return 0;
}
