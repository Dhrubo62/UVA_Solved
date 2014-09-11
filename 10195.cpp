/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 10195 - "The Knights Of The Round Table"
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
	double a,b,c;

	while(cin>>a>>b>>c)
	{
	   if((!a && !b)||(!b && !c)||(!c && !a)) printf("The radius of the round table is: 0.000\n");
	   else printf("The radius of the round table is: %.3lf\n",sqrt(((a+b-c)*(b+c-a)*(c+a-b))/(4.0*(a+b+c))));
	}

	return 0;
}
