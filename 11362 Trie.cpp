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

struct node
{
    bool end;
    node *next[10];

    node()
    {
        end=false;
        for( int i=0; i<10; i++ ) next[i] = NULL;
    }
} *root ;

void ins( string str )
{
    int len = str.size();
    node *cur = root;

    for( int i=0; i<len; i++ )
    {
        int dig = str[i] - '0';
        if( cur->next[dig] == NULL ) cur->next[dig] = new node();
        cur = cur->next[dig];
    }
    cur->end = true;
}

bool srch( string str )
{
    int len = str.size();
    node *cur = root;

    for( int i=0; i<len; i++ )
    {
        int dig = str[i] - '0';
        if( cur->next[dig] == NULL ) return false;
        cur = cur->next[dig];
    }
    return cur->end;
}

void del( node *cur )
{
    for( int i=0; i<10; i++ )
    {
        if( cur->next[i] !=NULL ) del( cur->next[i] );
    }
    delete( cur );
}

bool found( node *cur )
{
    int i;

    if( cur->end )
    {
        for( i=0; i<10; i++ ) if( cur->next[i] != NULL ) return true;
        if( i==10 ) return false;
    }

    for( int i=0; i<10; i++ )
    {
        if( cur->next[i]!=NULL && found( cur->next[i] ) ) return true;
    }
    if( i==10 ) return false;
}

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int t; cin>>t;
    while( t-- )
    {
        root = new node();

        int n; cin>>n;
        while( n-- )
        {
            string str; cin>>str;
            ins( str );
        }

        if( found(root) ) cout << "NO" << endl;
        else cout << "YES" << endl;

        del( root );
    }

    return 0;
}
