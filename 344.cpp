/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 344 - Roman Digititis
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

int cnt[110][5];

void pre_gen()
{
    cnt[1][0]=1;
    for(int p=2; p<=100; p++)
    {
        int n,num=p,i=0,v=0,x=0,l=0,c=0;

        //100
        n=num/100;
        c+=n;
        num-=100*n;

        //90
        n=num/90;
        x+=n; c+=n;
        num-=90*n;

        //50
        n=num/50;
        l+=n;
        num-=50*n;

        //40
        n=num/40;
        x+=n; l+=n;
        num-=n*40;

        //10
        n=num/10;
        x+=n;
        num-=10*n;

        //9
        n=num/9;
        i+=n; x+=n;
        num-=n*9;

        //5
        n=num/5;
        v+=n;
        num-=n*5;

        //4
        n=num/4;
        v+=n; i+=n;
        num-=n*4;

        //1
        i+=num;

        //store
        cnt[p][0]=cnt[p-1][0]+i;
        cnt[p][1]=cnt[p-1][1]+v;
        cnt[p][2]=cnt[p-1][2]+x;
        cnt[p][3]=cnt[p-1][3]+l;
        cnt[p][4]=cnt[p-1][4]+c;
    }
}

int main()
{
    //freopen("input.txt","r",stdin);

    pre_gen();

    int num;
    while(cin>>num && num)
    {
        printf("%d: %d i, %d v, %d x, %d l, %d c\n",num,cnt[num][0],cnt[num][1],cnt[num][2],cnt[num][3],cnt[num][4]);
    }

    return 0;
}
