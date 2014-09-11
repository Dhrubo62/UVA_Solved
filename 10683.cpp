/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 10683 - The decadary watch
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

    string str;
    while( cin >> str )
    {
       // cout <<  << endl;

        long long h = ( (str[0] - '0')*10 + (str[1] - '0') ) * 360000;
        long long m = ( (str[2] - '0')*10 + (str[3] - '0') ) * 6000;
        long long s = ( (str[4] - '0')*10 + (str[5] - '0') ) * 100;
        long long c = ( (str[6] - '0')*10 + (str[7] - '0') ) ;
        long long total = h + m + s + c;

        //cout << total << endl;

        total = ( total * 10000000) / 8640000;

        //cout << total << endl;

        c = total % 100;
        total /= 100;

        h = total / 10000;
        total %= 10000;

        m = total / 100;
        total %= 100;

        // output
        cout << h;
        if(m < 10) cout << 0; cout << m;
        if(total < 10) cout << 0; cout << total;
        if(c < 10) cout << 0; cout << c;
        cout << endl;
    }

    return 0;
}
