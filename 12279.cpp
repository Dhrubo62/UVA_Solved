/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 12279 - "Emoogle Balance"
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
	int n,supposed_to_give_a_treat,has_given_a_treat,num,csn=0;
	while(cin>>n && n)
	{
	    supposed_to_give_a_treat=has_given_a_treat=0;
	    while(n--)
	    {
	        cin>>num;
	        if(!num) has_given_a_treat++;
	        else supposed_to_give_a_treat++;
	    }

	    printf("Case %d: %d\n",++csn,supposed_to_give_a_treat-has_given_a_treat);
	}

	return 0;
}
