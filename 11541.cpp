/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11541 - Decoding
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
# include <sstream>
//}
using namespace std;

//{ ---------- Movements
/*int dx[]={1,-1,0,0}, dy[]={0,0,1,-1};*/ // 4 way movement
/*int dx[]={1,0,-1,0,1,-1,1,-1}, dy[]={0,1,0,-1,1,1,-1,-1};*/ // 8 way movement
//}

int main()
{
    //freopen("input.txt","r",stdin);

    int num,csn=0,t;
    char ch;
    string str;
    stringstream ss(str);

    cin>>t;
    while(csn++<t)
    {
        cin>>str;
        ss.clear();
        ss.str(str);

        cout<<"Case "<<csn<<": ";
        while(ss>>ch>>num)
        {
            while(num--) cout<<ch;
        }

        cout<<endl;
    }

    return 0;
}
