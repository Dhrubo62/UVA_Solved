/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11878 - "Homework Checker"
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
	char op,eql,res[100];
	int a,b,total=0,num;
	bool neg,ok;

	while(cin>>a>>op>>b>>eql>>res)
	{
	    num=0; neg=false; ok=true;
	    if(!strcmp(res,"?")) ok=false;
	    else
	    {
	        for(int i=0; res[i]; i++)
            {
                if(res[i]=='-') neg=true;
                else num = num*10 + res[i]-'0';
            }
            if(neg) num*=-1;
	    }

	    if(ok && ((op=='+' && a+b==num)||(op=='-' && a-b==num))) total++;
	}

	cout<<total<<endl;

	return 0;
}
