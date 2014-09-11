/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 459 - Graph Connectivity (Union Find Algorithm)
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

int par[50];

int find_parent(int x)
{
    if(par[x]!=x) par[x]=find_parent(par[x]);
    return par[x];
}

void connect(int x,int y)
{
    par[find_parent(x)]=find_parent(y);
}

int main()
{

    bool first=true;
    int t;
    cin>>t;

    while(t--)
    {
        char peak;
        cin>>peak;
        int ans=peak-'A'+1;

        for(int i=0; i<ans; i++) par[i]=i;

        getchar();
        string str;
        while(getline(cin,str) && str!="")
        {
            int a=str[0]-'A',b=str[1]-'A';

            if(find_parent(a)!=find_parent(b)) connect(a,b), ans--;
        }

        if(first) first=false;
        else cout<<endl;
        cout<<ans<<endl;
    }

    return 0;
}
