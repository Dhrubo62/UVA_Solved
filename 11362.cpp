/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11362 - Phone List
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

vector <string> list;
map <string,bool> m;
string str;
int csn,i;

int main()
{
    //freopen("input.txt","r",stdin);

    cin>>csn;
    while(csn--)
    {
        int key_num;
        cin>>key_num;
        while(key_num--)
        {
            cin>>str;
            list.push_back(str);
            m[str]=true;
        }

        int n=list.size();

        for(i=0; i<n; i++)
        {
            str="";
            int len=list[i].size();
            for(int j=0; j<len-1; j++)
            {
                str+=list[i][j];
                if(m[str])
                {
                    cout<<"NO"<<endl;
                    goto ending;
                }
            }
        }
        cout<<"YES"<<endl;

        ending:
        list.clear();
        m.clear();
    }

    return 0;
}
