/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 12555 - "B[a]by Me"
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
    int n,c=0,len,i,first,second;

    cin>>n;
    while(c<n)
    {
        cin>>str;
        len=str.size();
        first=second=0;

        for(i=0; str[i]>='0' && str[i]<='9' && i<len; i++)  first = first*10 + str[i]-'0';

        while(1)
        {
            if((str[i]>='0' && str[i]<='9') || i==len) break;
            else i++;
        }

        for( ; str[i]>='0' && str[i]<='9' && i<len; i++)    second = second*10 + str[i]-'0';

        cout<<"Case "<<++c<<": "<<first*0.5+second*0.05<<endl;
    }

	return 0;
}
