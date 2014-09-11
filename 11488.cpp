/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11488 - Hyper Prefix Sets
Catagory: Data Structures
Method: Trie (Prefix Tree) (ARRAY based)
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
# include <set>
//}
using namespace std;

//{ ---------- Movements
/*int dx[]={1,-1,0,0}, dy[]={0,0,1,-1};*/ // 4 way movement
/*int dx[]={1,0,-1,0,1,-1,1,-1}, dy[]={0,1,0,-1,1,1,-1,-1};*/ // 8 way movement
//}

int t,n,ttl;

struct node
{
    int cnt, len;
    int next[2];
    node()
    {
        len = 0;
        cnt = 0;
        next[0]=next[1]=-1;
    }
} trie[10000000+200] ;

void init()
{
    ttl=0;
    trie[ttl++] = node();
}

void add( char *str )
{
    int cur=0;
    int len=strlen(str);
    for( int i=0; i<len; i++ )
    {
        int c=str[i] - '0';

        if( trie[cur].next[c] == -1 )
        {
            // making new node
            trie[ttl] = node();
            trie[ttl].len = i+1;
            // linking
            trie[cur].next[c] = ttl++;
        }
        cur = trie[cur].next[c];
        trie[cur].cnt++;
    }
}

int calculate( int cur )
{
    int max_val = trie[cur].len * trie[cur].cnt;
    for( int i=0; i<2; i++ )
    {
        if(trie[cur].next[i]!=-1) max_val = max( max_val, calculate( trie[cur].next[i] ) );
    }
    return max_val;
}

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    cin >> t;
    while( t-- )
    {
        init();

        cin>>n;
        while( n-- )
        {
            char str[210];
            cin >> str;
            add( str );
        }

        cout << calculate(0) << endl;
    }

    return 0;
}
