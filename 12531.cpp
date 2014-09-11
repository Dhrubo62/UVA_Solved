/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 12531 - "Hours and Minutes"
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
	int angle;

	while(cin>>angle)
	{
	    if(angle%6) cout<<"N"<<endl;
	    else cout<<"Y"<<endl;
	}

	return 0;
}
