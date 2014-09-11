/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11221 - Magic square palindromes.
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

int t,csn,len;
string str;

bool square_number(int num)
{
    int root=sqrt(num*1.0);
    return root*root==num;
}

bool palindrome()
{
    for(int i=0; i<len/2; i++) if(str[i]!=str[len-i-1]) return false;
    return true;
}

int main()
{
    //freopen("input.txt","r",stdin);

    cin>>t;
    getchar();
    while(csn++<t)
    {
        getline(cin,str);
        for(int i=0; i<str.size(); )
        {
            if(str[i]>='a' && str[i]<='z') i++;
            else str.erase(i,1);
        }
        len=str.size();

        printf("Case #%d:\n",csn);
        if(square_number(len) && palindrome()) cout<<sqrt(len)<<endl;
        else cout<<"No magic :("<<endl;
    }

    return 0;
}
