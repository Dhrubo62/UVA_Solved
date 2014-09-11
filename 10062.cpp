/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 10062 - "Tell me the frequencies!"
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

struct type
{
    char ch;
    int cnt;
} flist[95];

int compare(type a,type b)
{
    return a.cnt==b.cnt ? a.ch>b.ch: a.cnt<b.cnt;
}

int main(void)
{
    char str[100000];
    int len;
    bool first=true;

    while(gets(str))
    {
        len=strlen(str);

        for(int i=0; i<95; i++)
        {
            flist[i].cnt=0;
            flist[i].ch = i+32;
        }

        for(int i=0; i<len; i++) flist[str[i]-32].cnt++;

        sort(flist,flist+95,compare);

        if(first) first=false;
        else cout<<endl;

        for(int i=0; i<95; i++)
        {
            if(flist[i].cnt)
            printf("%d %d\n",flist[i].ch,flist[i].cnt);
        }
    }

	return 0;
}
