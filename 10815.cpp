/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 10815 - Andy's First Dictionary
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

    //storage
    vector <string> words;
    map <string,bool> used;
    string str;

    //input and store
    while(cin>>str)
    {
        //processing
        bool in=false;
        string key="";
        for(int i=0; i<str.size(); i++)
        {
            if((str[i]>='A' && str[i]<='Z')||(str[i]>='a' && str[i]<='z'))
            {
                in=true;
                key+=tolower(str[i]);
            }
            else if(in)
            {
                in=false;
                if(!used[key]) {words.push_back(key); used[key]=true;}
                key="";
            }
        }

        if(in)
        {
            if(!used[key]) {words.push_back(key); used[key]=true;}
        }
    }

    //sorting
    sort(words.begin(),words.end());

    //output
    for(int i=0; i<words.size(); i++) cout<<words[i]<<endl;

    return 0;
}
