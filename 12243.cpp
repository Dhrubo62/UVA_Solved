/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 12243 - "Flowers Flourish from France"
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
	char str[10000],ref;
	bool first,ok;
	int len;

	while(gets(str) && strcmp(str,"*"))
	{
	    len=strlen(str); first=true; ok=true;
	    for(int i=0; i<len; i++)
	    {
	        if((!i || str[i-1]==' ') && ((str[i]>='a'&&str[i]<='z')||(str[i]>='A'&&str[i]<='Z')))
	        {
	            if(first) {first=false; ref=toupper(str[i]);}
	            else if(toupper(str[i])!=ref) {ok=false; break;}
	        }
	    }

	    if(ok) cout<<"Y"<<endl;
	    else cout<<"N"<<endl;
	}

	return 0;
}
