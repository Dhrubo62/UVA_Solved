/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11723 - Numbering Roads!
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

    long long r,n,ltr,rem;
    int csn=0;

    while(cin>>r>>n && !(!r && !n))
    {
        ltr=r/n; rem=r%n;
        if(rem) ltr++;

        printf("Case %d: ",++csn);
        if(ltr>27) cout<<"impossible"<<endl;
        else cout<<ltr-1<<endl;
    }

    return 0;
}
