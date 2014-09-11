/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11060 - Beverages
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

int indegree[110],n,m;
string str;
vector <int> top,adjacent[110],q;
map <string,int> value;
map <int,string> name;

void main_clean()
{
    for(int i=0; i<n; i++) indegree[i]=0, adjacent[i].clear();
    value.clear();
    name.clear();
}

void top_clean()
{
    top.clear();
    q.clear();
}

void top_sort()
{
    top_clean();

    for(int i=0; i<n; i++) if(!indegree[i]) q.push_back(i);

    while(q.size())
    {
        sort(q.begin(),q.end());

        int u=q[0]; q.erase(q.begin());
        top.push_back(u);

        for(int i=0; i<adjacent[u].size(); i++)
        {
            int v=adjacent[u][i];
            indegree[v]--;
            if(!indegree[v]) q.push_back(v);
        }
    }
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int csn=0;
    while(cin>>n)
    {
        main_clean();
        for(int i=0; i<n; i++)
        {
            cin>>str;
            value[str]=i;
            name[i]=str;
        }

        cin>>m;
        for(int i=0; i<m; i++)
        {
            cin>>str;
            int u=value[str];

            cin>>str;
            int v=value[str];

            adjacent[u].push_back(v);
            indegree[v]++;
        }

        printf("Case #%d: Dilbert should drink beverages in this order:",++csn);
        top_sort();
        for(int i=0; i<top.size(); i++) cout<<" "<<name[top[i]];
        cout<<"."<<endl<<endl;
    }

    return 0;
}
