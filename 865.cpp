/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 865 - Substitution Cypher
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
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int t;
    cin>>t; getchar();

    string del; getline(cin,del); //to delete the first blank line

    while(t--)
    {
        string str,first,second;
        map <char,char> m;

        getline(cin,first);
        getline(cin,second);
        for(int i=0; i<first.size() && i<second.size(); i++) m[first[i]]=second[i];

        cout<<second<<endl<<first<<endl;
        while(getline(cin,str))
        {

            for(int i=0; i<str.size(); i++)
            {
                if(m.find(str[i])!=m.end()) str[i]=m[str[i]];
            }

            cout<<str<<endl;
            if(!str.size()) break;
        }
    }
    return 0;
}
