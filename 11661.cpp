/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11661 - "Burger Time?"
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

int main()
{
	int n,minimum_distance,i,start;
	string road;
	bool first,zero,r;

    while(cin>>n && n)
    {
        cin>>road;
        zero=false; first=true;

        //forward check
        r=false;
        for(i=0; i<n; i++)
        {
            if(road[i]=='Z') {zero=true; goto escape;}
            else if(road[i]=='R') {r=true; start=i;}
            else if(road[i]=='D' && r)
            {
                if(first) {minimum_distance=i-start; first=false;}
                else if(minimum_distance>i-start) minimum_distance=i-start;
                r=false;
            }
        }

        //backward check
        r=false;
        for(i=n-1; i>=0; i--)
        {
            if(road[i]=='Z') {zero=true; goto escape;}
            else if(road[i]=='R') {r=true; start=i;}
            else if(road[i]=='D' && r)
            {
                if(first) {minimum_distance=start-i; first=false;}
                else if(minimum_distance>start-i) minimum_distance=start-i;
                r=false;
            }
        }

        escape:
        if(zero) cout<<"0"<<endl;
        else cout<<minimum_distance<<endl;
    }

	return 0;
}
