/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11830 - "Contract revision"
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

void reverse(char *p)
{
    char c; int len=strlen(p);
    for(int i=0; i<len/2; i++)
    {
        c=p[i];
        p[i]=p[len-i-1];
        p[len-i-1]=c;
    }
}

void kill_zero(char *p)
{
    int len=strlen(p)-1;
    while(len>=0)
    {
        if(p[len]=='0') p[len--]='\0';
        else break;
    }
}

void del(char k,char *p)
{
    int len=strlen(p);
    for(int i=0; i<len; )
    {
        if(p[i]==k) {for(int j=i; j<len-1; j++) p[j]=p[j+1]; p[--len]='\0';}
        else i++;
    }
}

int main()
{
	char ch,str[100000];

	while(cin>>ch>>str && strcmp(str,"0"))
	{
	    del(ch,str);
	    reverse(str);
	    kill_zero(str);
	    reverse(str);

	    if(!strcmp(str,"")) cout<<0<<endl;
	    else cout<<str<<endl;
	}

	return 0;
}
