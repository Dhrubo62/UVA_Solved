/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11062 - Andy's Second Dictionary
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

vector <string> word;
map <string,bool> used;
string str,key="";
bool in=false;

bool valid(char a)
{
    if(a>='A' && a<='Z') return true;
    if(a>='a' && a<='z') return true;
    return false;
}

void push()
{
    if(key.size() && !used[key])
    {
        word.push_back(key);
        used[key]=true;
    }

    key=""; in=false;
}

int main()
{
    //freopen("input.txt","r",stdin);

    while(getline(cin,str))
    {
        for(int i=0; i<=str.size(); i++)
        {
            if(valid(str[i]))
            {
                in=true;
                key+=tolower(str[i]);
            }
            else if(str[i]=='-')
            {
                if(i!=str.size()-1 && valid(str[i+1]) && i && valid(str[i-1])) key+=str[i];
                else if(i!=str.size()-1) push();
            }
            else if(in && str[i-1]!='-') push();
        }
    }

    sort(word.begin(),word.end());
    for(int i=0; i<word.size(); i++) cout<<word[i]<<endl;

    return 0;
}
