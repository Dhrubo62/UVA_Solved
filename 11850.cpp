/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11850 - "Alaska"
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

int main(void)
{
    int point[1500],n,i,turn;
    bool possible;

    while(cin>>n && n)
    {
        //input
        for(i=0; i<n; i++) cin>>point[i];

        //sort distances and add the last one
        sort(point,point+n);

        //check
        possible=true;
        for(i=1; i<n; i++)
        {
            if(point[i]-point[i-1]>200)
            {
                possible=false;
                break;
            }
        }

        //last check for returning back
        if(possible)
        {
            if((1422-point[n-1])*2>200) possible=false;
        }

        //result
        if(possible) cout<<"POSSIBLE"<<endl;
        else cout<<"IMPOSSIBLE"<<endl;
    }

	return 0;
}
