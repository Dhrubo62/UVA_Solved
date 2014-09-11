/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11787 - Numeral Hieroglyphs
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

map <char,unsigned long long> m;

bool cmp1(char a,char b)
{
    return m[a]>m[b];
}

bool cmp2(char a,char b)
{
    return m[a]<m[b];
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    m['B']=1;
    m['U']=10;
    m['S']=100;
    m['P']=1000;
    m['F']=10000;
    m['T']=100000;
    m['M']=1000000;

    int t;
    cin>>t;
    while(t--)
    {
        string str,tmp1,tmp2;

        cin>>str;

        tmp1=tmp2=str;
        sort(tmp1.begin(),tmp1.end(),cmp1);
        sort(tmp2.begin(),tmp2.end(),cmp2);

        if(str!=tmp1 && str!=tmp2) {cout<<"error"<<endl; continue;}

        char last='X';
        int len=str.size(),cnt=0;
        bool ok=true;
        unsigned long long num=0;

        for(int i=0; i<len; i++)
        {
            if(str[i]==last) cnt++;
            else cnt=1;

            last=str[i];
            num+=m[str[i]];

            if(cnt>9) {ok=false; break;}
        }

        if(!ok) cout<<"error"<<endl;
        else cout<<num<<endl;
    }

    return 0;
}
