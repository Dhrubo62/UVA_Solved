/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 468 - Key to Success
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

map <char,int> cnt;

bool compare(char a,char b)
{
    return cnt[a]>cnt[b];
}

int main()
{
    //freopen("input.txt","r",stdin);

    bool first=true;
    int t;
    cin>>t;
    getchar();
    while(t--)
    {
        //storage
        string str;
        getline(cin,str); //clears the blank line

        //first string
        getline(cin,str);
        cnt.clear();
        vector <char> kl;
        for(int i=0; i<str.size(); i++)
        {
            if(!cnt[str[i]])
            {
                cnt[str[i]]=1;
                kl.push_back(str[i]);
            }
            else cnt[str[i]]++;
        }
        sort(kl.begin(),kl.end(),compare);

        //second string
        getline(cin,str);
        cnt.clear();
        vector <char> ll;
        for(int i=0; i<str.size(); i++)
        {
            if(!cnt[str[i]])
            {
                cnt[str[i]]=1;
                ll.push_back(str[i]);
            }
            else cnt[str[i]]++;
        }
        sort(ll.begin(),ll.end(),compare);

        //mapping
        map <char,bool> mapped;
        map <char,char> m;
        for(int i=0; i<ll.size() && i<kl.size(); i++)
        {
            mapped[ll[i]]=true;
            m[ll[i]]=kl[i];
        }

        //replacement
        for(int i=0; i<str.size(); i++) if(mapped[str[i]]) str[i]=m[str[i]];

        //output
        if(!first) cout<<endl;
        first=false;
        cout<<str<<endl;
    }

    return 0;
}
