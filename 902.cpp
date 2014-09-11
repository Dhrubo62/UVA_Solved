/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 902 - Password Search
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

int main()
{
    //freopen("input.txt","r",stdin);

    int n;
    string str;
    while(cin>>n>>str)
    {
        int len=str.size(),cnt=0;
        string part,mx;
        map <string,int> m;

        for(int i=0; i<=len-n; i++)
        {
            part="";
            for(int j=i; j<=i+n-1; j++) part+=str[j];

            if(m.find(part)==m.end()) m[part]=1;
            else m[part]++;

            if(m[part]>cnt) cnt=m[part], mx=part;
        }

        cout<<mx<<endl;
    }

    return 0;
}
