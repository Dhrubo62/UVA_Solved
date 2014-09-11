/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 762 - "We Ship Cheap"
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

// ------------------ Movements
/*int dx[]={1,-1,0,0}, dy[]={0,0,1,-1};*/ // 4 way movement
/*int dx[]={1,0,-1,0,1,-1,1,-1}, dy[]={0,1,0,-1,1,1,-1,-1};*/ // 8 way movement

using namespace std;

struct stype
{
    int c;
    string path;
};

int main()
{
	int n,i;
	bool first_print=true;

	while(cin>>n)
	{
	    //storage
	    vector <string> city;
	    vector <int> list[100000];
	    string first,second;
	    int x,y,fx,fy;

	    //input
	    while(n--)
	    {
	        cin>>first>>second;

	        //organizing first one
	        for(i=0; i<city.size(); i++) if(city[i]==first) break;
	        if(i==city.size()) city.push_back(first);
	        x=i;

	        //organizing second one
	        for(i=0; i<city.size(); i++) if(city[i]==second) break;
	        if(i==city.size()) city.push_back(second);
	        y=i;

	        list[x].push_back(y); list[y].push_back(x);
	    }

	    //input final destination
	    cin>>first>>second;
	    for(i=0; i<city.size(); i++) if(city[i]==first) break; fx=i;
	    for(i=0; i<city.size(); i++) if(city[i]==second) break; fy=i;

	    //bfs initialization
	    stype push,now;
	    queue <stype> q;
	    bool mark[100000]; memset(mark,false,sizeof mark);

	    //bfs routine
	    bool route_is_found=false;
	    push.c=fx; push.path="";
	    q.push(push); mark[fx]=true;
	    while(!q.empty())
	    {
	        now=q.front(); q.pop();
	        if(now.c==fy) {route_is_found=true; break;}

	        x=now.c;
	        for(i=0; i<list[x].size(); i++)
	        {
	            push.c=list[x][i];
	            if(!mark[push.c])
	            {
	                push.path=now.path+city[x]+" "+city[push.c]+"\n";
                    q.push(push); mark[push.c]=true;
	            }
	        }
	    }

	    //output
	    if(first_print) first_print=false;
	    else cout<<endl;

	    if(route_is_found)
	    {
	        if(now.path=="") cout<<"No route"<<endl;
	        else cout<<now.path;
	    }
	    else cout<<"No route"<<endl;
	}

	return 0;
}
