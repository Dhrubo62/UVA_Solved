/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 12750 - Keep Rafa at Chelsea
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

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int CASE = 1;
    int t; cin >> t;
    while( t-- )
    {
        int n; cin >> n;

        int noWin = 0, jobDay;
        bool ok = true;
        for(int i=0; i<n; i++)
        {
            char ch; cin >> ch;

            if(ok)
            {
                if( ch == 'W' ) noWin = 0;
                else
                {
                    noWin++;
                    if( noWin == 3 )
                    {
                        ok = false;
                        jobDay = i+1;
                    }
                }
            }
        }

        cout << "Case " << CASE++ << ": ";
        if(ok) cout << "Yay! Mighty Rafa persists!" << endl;
        else cout << jobDay << endl;
    }

    return 0;
}
