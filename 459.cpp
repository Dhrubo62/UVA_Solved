/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 459 - "Graph Connectivity"
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

char nodes;
bool mark[50];
vector <int> list[50];

void dfs(int x)
{
    mark[x]=true;
    for(int i=0; i<list[x].size(); i++)
    {
        int y=list[x][i];
        if(!mark[y]) dfs(y);
    }
}

int main()
{
	int t,i;
	bool first=true;
	cin>>t;
	while(t--)
	{
	    cin>>nodes; nodes=nodes-'A'+1;
	    getchar();

	    for(i=0; i<50; i++) list[i].clear();
	    string str;
	    while(getline(cin,str) && str!="")
	    {
	        list[str[0]-'A'].push_back(str[1]-'A');
	        list[str[1]-'A'].push_back(str[0]-'A');
	    }

	    memset(mark,false,sizeof mark);
	    int ttl=0;
	    for(i=0; i<nodes; i++) if(!mark[i]) {ttl++; dfs(i);}

	    if(first) first=false;
	    else cout<<endl;
	    cout<<ttl<<endl;
	}

	return 0;
}
