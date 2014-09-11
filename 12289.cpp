/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 12289
*/

# include <iostream>
# include <cstdio>
# include <cstring>
# include <cmath>
# include <cstdlib>
# include <algorithm>

using namespace std;

int main(void)
  {
	char str[1000000];
	int t,l;
	cin>>t;
	getchar();
	while(t)
	{
	    gets(str);
	    l=strlen(str);
	    if(l==3)
	    {
	        if((str[0]=='o'&&str[1]=='n')||(str[1]=='n'&&str[2]=='e')||(str[0]=='o'&&str[2]=='e'))
	        cout<<1<<endl;
	        else
	        cout<<2<<endl;
	    }
	    else
	    cout<<3<<endl;

	    t--;
	}

	return 0;
  }
