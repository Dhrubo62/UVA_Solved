/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 10115 - Automatic Editing
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
    while(cin>>n && n)
    {
        getchar();

        //declaration
        string str,str2;
        vector <string> v,w;
        int len;

        //input
        for(int i=0; i<n; i++)
        {
            getline(cin,str);
            getline(cin,str2);

            v.push_back(str);
            w.push_back(str2);
        }
        getline(cin,str);

        //process
        for(int i=0; i<n; i++)
        {
            string key,word;
            int lk,lw;

            key=v[i]; lk=key.size();
            word=w[i]; lw=word.size();

            while(str.find(key)!=string::npos)
            {
                int index=str.find(key);

                str.erase(index,lk);
                str.insert(index,word);
            }
        }

        //output
        cout<<str<<endl;
    }

    return 0;
}
