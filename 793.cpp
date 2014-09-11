/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 793 - Network Connections
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
//}
using namespace std;

//{ ---------- Movements
/*int dx[]={1,-1,0,0}, dy[]={0,0,1,-1};*/ // 4 way movement
/*int dx[]={1,0,-1,0,1,-1,1,-1}, dy[]={0,1,0,-1,1,1,-1,-1};*/ // 8 way movement
//}

int par[1000010];

int parent(int x)
{
    if(par[x]!=x) par[x]=parent(par[x]);
    return par[x];
}

int main()
{
    bool first=true;
    int t;
    cin>>t;
    while(t--)
    {
        int n,yes=0,no=0;
        cin>>n;
        for(int i=1; i<=n; i++) par[i]=i;

        char str[10000];
        getchar();
        while(gets(str) && strcmp(str,""))
        {
            char ch;
            int u,v;

            sscanf(str,"%c%d%d",&ch,&u,&v);

            int x=parent(u), y=parent(v);
            if(ch=='c' && x!=y) par[x]=y;
            else if(ch=='q') x==y? yes++: no++;
        }

        if(first) first=false;
        else cout<<endl;
        printf("%d,%d\n",yes,no);
    }

    return 0;
}
