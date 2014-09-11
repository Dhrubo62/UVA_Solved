/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch
Problem: UVA - 10336 - Rank the Languages
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
int dx[]={1,-1,0,0}, dy[]={0,0,1,-1}; // 4 way movement
/*int dx[]={1,0,-1,0,1,-1,1,-1}, dy[]={0,1,0,-1,1,1,-1,-1};*/ // 8 way movement

struct container
{
    char ch;
    int cnt;
};

int compare(container a,container b)
{
    if(a.cnt==b.cnt) return a.ch<b.ch;
    else return a.cnt>b.cnt;
}

int r,c,total,lan;
char grid[1010][1010],key;
bool mark[1010][1010];
map <char,int> m;
vector <container> list_Language;
container language;

void dfs(int x,int y)
{
    mark[x][y]=true;
    total++;
    for(int i=0; i<4; i++)
    {
        int nx=x+dx[i]; int ny=y+dy[i];
        if(nx>=0 && nx<r && ny>=0 && ny<c && !mark[nx][ny] && grid[nx][ny]==key) dfs(nx,ny);
    }
}

int main()
{
    int t,csn=0,i,j;
    cin>>t;
    while(csn<t)
    {
        cin>>r>>c;
        for(i=0; i<r; i++) cin>>grid[i];

        memset(mark,false,sizeof mark);
        lan=0;
        m.clear(); list_Language.clear();
        for(i=0; i<r; i++) for(j=0; j<c; j++) if(!mark[i][j])
        {
            key=grid[i][j];
            total=0;
            dfs(i,j);

            if(m.find(key)==m.end())
            {
                m[key]=lan++;
                language.ch=key; language.cnt=1;
                list_Language.push_back(language);
            }
            else list_Language[m[key]].cnt++;
        }

        printf("World #%d\n",++csn);
        sort(list_Language.begin(),list_Language.end(),compare);
        for(i=0; i<list_Language.size(); i++) printf("%c: %d\n",list_Language[i].ch,list_Language[i].cnt);
    }

    return 0;
}

