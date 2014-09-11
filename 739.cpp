/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 739 - Soundex Indexing
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
//}
using namespace std;

//{ ---------- Movements
/*int dx[]={1,-1,0,0}, dy[]={0,0,1,-1};*/ // 4 way movement
/*int dx[]={1,0,-1,0,1,-1,1,-1}, dy[]={0,1,0,-1,1,1,-1,-1};*/ // 8 way movement
//}

map <char,char> m;
void mapping()
{
    m[ 'B' ] = '1';
    m[ 'P' ] = '1';
    m[ 'F' ] = '1';
    m[ 'V' ] = '1';

    m[ 'C' ] = '2';
    m[ 'S' ] = '2';
    m[ 'K' ] = '2';
    m[ 'G' ] = '2';
    m[ 'J' ] = '2';
    m[ 'Q' ] = '2';
    m[ 'X' ] = '2';
    m[ 'Z' ] = '2';

    m[ 'D' ] = '3';
    m[ 'T' ] = '3';

    m[ 'L' ] = '4';

    m[ 'M' ] = '5';
    m[ 'N' ] = '5';

    m[ 'R' ] = '6';

    // non codable
    m[ 'A' ] = '?';
    m[ 'E' ] = '?';
    m[ 'I' ] = '?';
    m[ 'O' ] = '?';
    m[ 'U' ] = '?';
    m[ 'Y' ] = '?';
    m[ 'W' ] = '?';
    m[ 'H' ] = '?';
}

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    mapping();
    string line;

    line = "";
    line.resize( 9, ' ' );
    line += "NAME";
    line.resize( 34, ' ' );
    line += "SOUNDEX CODE";
    cout << line << endl;

    string str;
    while( cin >> str )
    {
        string coded = "";

        coded += str[0];
        char last = m[ str[0] ] ;
        for(int i=1; i<str.size(); i++)
        {
            char now = m[ str[i] ];

            if( now!='?' && now!=last ) coded += now;

            last = now;
        }

        // processing output
        coded.resize(4,'0');
        string out = "";

        out.resize(9,' ');
        out += str;

        out.resize(34,' ');
        out += coded;

        // output
        cout << out << endl;
    }

    line = "";
    line.resize(19, ' ' );
    line += "END OF OUTPUT";
    cout << line << endl;

    return 0;
}
