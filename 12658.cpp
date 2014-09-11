/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 12658 - "Character Recognition?"
*/

# include <iostream>
# include <cstdio>
# include <cstring>
# include <string>
# include <cmath>
# include <cstdlib>
# include <algorithm>
# include <cctype>
# include <vector>
# include <queue>

using namespace std;

int main()
{
	int n,i;
	string str;

	cin>>n;
	for(i=0; i<4; i++) cin>>str;

	for(i=0; i<n; i++)
	{
	    if(str[i*4]=='*') cout<<2;
	    else if(str[i*4+2]=='*') cout<<3;
	    else cout<<1;
	}
	cout<<endl;

	return 0;
}
