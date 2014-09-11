/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 452 - Project Scheduling
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
# include <set>
//}
using namespace std;

//{ ---------- Movements
/*int dx[]={1,-1,0,0}, dy[]={0,0,1,-1};*/ // 4 way movement
/*int dx[]={1,0,-1,0,1,-1,1,-1}, dy[]={0,1,0,-1,1,1,-1,-1};*/ // 8 way movement
//}

int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    bool first=true;
    int t; cin>>t; getchar();
    string line;
    getline(cin,line);
    while(t--) {
        // memory
        vector <int> ind(27,0), graph[27], start(27,0);
        int t[27];
        queue <int> temp,q;
        map <char,bool> task;

        // input
        while( getline(cin,line) && line!="" ) {
            stringstream sin(line);

            char u; sin>>u; u-='A';

            if(task[u]) continue;
            task[u] = true;

            sin>>t[u];

            string list; sin>>list;
            ind[u] = list.size();

            map <int,bool> desti;
            for( int i=0; i<list.size(); i++ ) {
                int v = list[i]-'A';

                if(desti[v]) continue;
                desti[v] = true;

                graph[ v ].push_back( u );
            }
            if(!ind[u]) {
                q.push( u );
            }
        }

        //calculate time with topological sorting
        int passed_time=0, max_time=0;
        while( !q.empty() ) {
            int u=q.front(); q.pop();
            passed_time = start[u] + t[u];
            max_time = max(max_time,passed_time);

            for( int i=0; i<graph[u].size(); i++ ) {
                int v = graph[u][i];
                start[v] = max(passed_time,start[v]);
                ind[v]--;
                if(!ind[v]) {
                    q.push(v);
                }
            }
        }

        //output
        if(!first) cout << endl;
        first = false;
        cout << max_time << endl;
    }

    return 0;
}
