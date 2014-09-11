/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 10992 - "The Ghost of Programmers"
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

char year[100];
int len;

bool mod(int x)
{
    int m=0,i;
    for(i=0; i<len; i++)
    {
        m=m*10+year[i]-'0';  m%=x;
    }
    return m==2148%x;
}

bool leap()
{
    int m=0,i;
    for(i=0; i<len; i++)
    {
        m=m*10+year[i]-'0';  m%=400;
    }
    if(!m) return true;

    m=0;
    for(i=0; i<len; i++)
    {
        m=m*10+year[i]-'0';  m%=4;
    }
    if(!m)
    {
        m=0;
        for(i=0; i<len; i++)
        {
            m=m*10+year[i]-'0';  m%=100;
        }
        if(m) return true;
        else return false;
    }
    else return false;
}

bool value_is_zero()
{
    bool zero=true;
    for(int i=0; i<len; i++)
    {
        if(year[i]!='0')
        {
            zero=false; break;
        }
    }
    return zero;
}

bool valid_year()
{
    if(len<4) return false;
    if(len>4) return true;

    if(atoi(year)>=2148) return true;
    else return false;
}

int main(void)
{
	bool first=true;
	while(cin>>year)
	{
	    len=strlen(year);
	    if(value_is_zero()) break;

	    if(first) first=false;
	    else cout<<endl;
	    cout<<year<<endl;

	    if(valid_year())
	    {
	        bool printed=false;

	        if(mod(2)) { cout<<"Ghost of Tanveer Ahsan!!!"<<endl; printed=true; }
            if(mod(5)) { cout<<"Ghost of Shahriar Manzoor!!!"<<endl; printed=true; }
            if(mod(7)) { cout<<"Ghost of Adrian Kugel!!!"<<endl; printed=true; }
            if(mod(11)) { cout<<"Ghost of Anton Maydell!!!"<<endl; printed=true; }
            if(mod(15)) { cout<<"Ghost of Derek Kisman!!!"<<endl; printed=true; }
            if(mod(20)) { cout<<"Ghost of Rezaul Alam Chowdhury!!!"<<endl; printed=true; }
            if(mod(28)) { cout<<"Ghost of Jimmy Mardell!!!"<<endl; printed=true; }
            if(mod(36)) { cout<<"Ghost of Monirul Hasan!!!"<<endl; printed=true; }
            if(leap()) { cout<<"Ghost of K. M. Iftekhar!!!"<<endl; printed=true; }

            if(!printed) cout<<"No ghost will come in this year"<<endl;
	    }
	    else cout<<"No ghost will come in this year"<<endl;
	}

	return 0;
}
