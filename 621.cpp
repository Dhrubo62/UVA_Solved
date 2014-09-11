/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 621 - "Secret Research"
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
	string str;
	int len,n;

	cin>>n;

	while(n)
	{
	    cin>>str;
	    len=str.size();

	    if(str=="1" || str=="4" || str=="78")
	    cout<<'+'<<endl;
	    else if(str[len-1]=='5' && str[len-2]=='3')
	    cout<<'-'<<endl;
	    else if(str[0]=='9' && str[len-1]=='4')
	    cout<<'*'<<endl;
	    else
	    cout<<'?'<<endl;

	    n--;
	}

	return 0;
}
