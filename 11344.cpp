/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11344 - "The Huge One"
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

string number;
int len;

bool check(int num)
{
    int i,rem=0;
    for(i=0; i<len; i++)
    {
        rem=rem*10+number[i]-'0';
        rem%=num;
    }

    return rem ? false: true;
}

int main()
{
	int t;

	cin>>t;
	while(t--)
	{
	    cin>>number;
        len=number.size();

	    int num,n;
	    bool ok=true;

	    cin>>n;
	    while(n--)
	    {
	        cin>>num;
	        if(!check(num)) ok=false;
	    }

	    cout<<number<<" - ";
	    if(ok) cout<<"Wonderful."<<endl;
	    else cout<<"Simple."<<endl;
	}

	return 0;
}
