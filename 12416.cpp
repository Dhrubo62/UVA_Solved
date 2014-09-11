/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 12416 - "Excessive Space Remover"
*/

// ----------------- C headers
# include <cstdio>
# include <cstring>
# include <cmath>
# include <cstdlib>
# include <cctype>

// ----------------- C++ headers
# include <iostream>
# include <string>
# include <algorithm>
# include <vector>
# include <queue>

//------------------ Movements
/*int dx[]={1,-1,0,0}, dy[]={0,0,1,-1};*/ // 4 way movement
/*int dx[]={1,0,-1,0,1,-1,1,-1}, dy[]={0,1,0,-1,1,1,-1,-1};*/ // 8 way movement


using namespace std;

int main()
{
    string str;
    bool space;

    while(getline(cin,str))
    {
        int len=str.size(),max=0,i,cnt,rem;

        space=false; cnt=0;
        for(i=0; i<len; i++)
        {
            if(str[i]==' ')
            {
                space=true;
                cnt++;
            }
            else if(str[i]!=' ')
            {
                if(space) {if(cnt>max) max=cnt; cnt=0; space=false;}
            }
        }
        if(space) if(cnt>max) max=cnt;

        cnt=0;
        while(max>1)
        {
            rem=max%2;
            max=max/2+rem;
            cnt++;
        }

        cout<<cnt<<endl;
    }

	return 0;
}
