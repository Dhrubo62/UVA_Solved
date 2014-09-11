/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11321 - "Sort! Sort!! And Sort!!!"
*/

# include <iostream>
# include <cstdio>
# include <cstring>
# include <string>
# include <cmath>
# include <cstdlib>
# include <algorithm>
# include <cctype>

using namespace std;

int m;

int compare(int a, int b)
{
    int ma=1,mb=1;
    bool f=false,s=false;

    if(a<0)
    {
        ma *= -1;
        a *= -1;
        f=true;
    }
    if(b<0)
    {
        mb *= -1;
        b *= -1;
        s=true;
    }
    ma *= a%m;
    mb *= b%m;

    if(f) a *= -1;
    if(s) b *= -1;

    if(ma==mb)
    {
        int x,y;
        if(a%2) x=1;
        else x=2;
        if(b%2) y=1;
        else y=2;

        if(x==y)
        {
            if(x==1)
            {
                return a>b;
            }
            else
            {
                return a<b;
            }
        }
        else return x<y;
    }
    else return ma < mb;
}

int main(void)
{
    int list[10010],n,i;

    while(cin>>n>>m)
    {
        printf("%d %d\n",n,m);
        if(!n && !m) break;

        for(i=0; i<n; i++) cin>>list[i];

        sort(list,list+n,compare);

        for(i=0; i<n; i++) cout<<list[i]<<endl;
    }

	return 0;
}
