/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 924 - Spreading The News
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
# include <stack>
# include <map>
# include <sstream>
//}
using namespace std;

//{ ---------- Movements
/*int dx[]={1,-1,0,0}, dy[]={0,0,1,-1};*/ // 4 way movement
/*int dx[]={1,0,-1,0,1,-1,1,-1}, dy[]={0,1,0,-1,1,1,-1,-1};*/ // 8 way movement
//}

struct boom
{
    int person, day;

    boom(int x,int y)
    {
        person = x;
        day = y;
    }
};
queue <boom> q;

int e, queries, source;
vector <int> grid[2510], dayList;
map <int,int> onDay;
map <int,bool> heared;

void refresh()
{
    while(!q.empty()) q.pop();
    heared.clear();
    onDay.clear();
    dayList.clear();
}

bool compare(int x,int y)
{
    if( onDay[x] != onDay[y] ) return onDay[x] > onDay[y];
    else return x < y;
}

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    cin >> e;

    // storing the grid
    for(int i=0; i<e; i++)
    {
        int n; cin >> n;
        while( n-- )
        {
            int frnd; cin >> frnd;
            grid[i].push_back( frnd );
        }
    }

    // inputing queries and generating output
    cin >> queries;
    while( queries-- )
    {
        refresh();

        cin >> source;

        q.push( boom( source, 0 ) ); heared[ source ] = true;

        while(!q.empty())
        {
            int person = q.front().person, day = q.front().day;
            q.pop();

            for(int i=0; i<grid[ person ].size(); i++)
            {
                int nextPerson = grid[ person ][i];

                if(!heared[ nextPerson ])
                {
                    int nextDay = day + 1;

                    if( !onDay[ nextDay ] )
                    {
                        onDay[ nextDay ] = 1;
                        dayList.push_back( nextDay );
                    }
                    else onDay[ nextDay ]++;

                    q.push( boom( nextPerson, nextDay ) ); heared[ nextPerson ] = true;
                }
            }
        }

        // output
        if(!dayList.size()) cout<<0<<endl;
        else
        {
            sort( dayList.begin(), dayList.end(), compare );
            cout << onDay[ dayList[0] ] << " "<< dayList[0] << endl;
        }
    }

    return 0;
}
