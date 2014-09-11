/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 10427 - "Naughty Sleepy Boys"
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
	int num,max=1,i;
	string str="";

	while(cin>>num)
	{
	    char number[100];

	    if(num<=str.size()) cout<<str[num-1]<<endl;
	    else
	    {
	        for(i=max; str.size()<num; i++)
            {
                sprintf(number,"%d",i);
                str+=number;
            }
            max=i;
            cout<<str[num-1]<<endl;
	    }
    }

	return 0;
}
