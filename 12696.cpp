/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 12696 - "Cabin Baggage"
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
	int n,total=0;
	bool ok;
	double a,b,c,w;

	cin>>n;
	while(n)
	{
	    cin>>a>>b>>c>>w;

	    //check
	    ok=true;
	    if(w>7.0) ok=false;
	    if((a>56.0 || b>45.0 || c>25.0) && a+b+c>125) ok=false;

	    //print
	    cout<<ok<<endl;
	    total+=ok;

	    n--;
	}
	cout<<total<<endl;

	return 0;
}
