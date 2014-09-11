/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11220 - Decoding the message.
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

    int t,csn=0;
    bool first=true;
    string line;

    cin>>t;
    getchar();
    getline(cin,line); //to clear the first blank line
    while(t--)
    {

        if(!first) cout<<endl;
        first=false;
        cout<<"Case #"<<++csn<<":"<<endl;

        while(getline(cin,line) && line!="")
        {
            stringstream ss(line);
            string word,out="";
            int cnt=0;

            while(ss>>word)
            {
                if(word.size()>cnt)
                {
                    out+=word[cnt++];
                }
            }

            cout<<out<<endl;
        }
    }

    return 0;
}
