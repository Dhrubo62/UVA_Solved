/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 10878 - Decode the tape
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

    string str;

    while(getline(cin,str))
    {
        if(str[0]=='|')
        {
            int mid,val=0,p;

            for(int i=0; i<str.size(); i++) if(str[i]=='.') {mid=i; break;}

            p=2;
            for(int i=mid+1; i<=mid+3; i++,p--)
                if(str[i]=='o') val+=(int)pow(2.0,p*1.0);

            p=3;
            for(int i=mid-1; i>=0; i--,p++)
                if(str[i]=='o') val+=(int)pow(2.0,p*1.0);

            cout<<(char)val;
        }
    }

    return 0;
}
