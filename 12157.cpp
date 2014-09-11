/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA- 12157 - Tariff Plan
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

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int CASE = 1;
    int t; cin >> t;
    while( t-- )
    {
        int mile=0, juice=0;

        int n; cin >> n;
        while( n-- )
        {
            int sec; cin >> sec; sec++;
            int cent, rem;

            // mile count
            cent = sec / 30; rem = sec % 30;
            if(rem) cent++;
            mile += cent * 10;

            // juice count
            cent = sec / 60; rem = sec % 60;
            if(rem) cent++;
            juice += cent * 15;
        }

        cout << "Case " << CASE++ << ": ";
        if( mile == juice ) cout << "Mile Juice " << mile << endl;
        else if( mile < juice ) cout << "Mile " << mile << endl;
        else cout << "Juice " << juice << endl;
    }

    return 0;
}
