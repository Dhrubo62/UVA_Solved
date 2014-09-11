/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 10013 - "Super long sums"
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

void reverse(char *p,int len)
{
    char temp;

    for(int i=0; i<len/2; i++)
    {
        temp=p[i];
        p[i]=p[len-i-1];
        p[len-i-1]=temp;
    }
}

int main(void)
{
	int n,m,carry,i;
	char num1[1000001],num2[1000001];
	bool first=true;

	cin>>n;
	while(n)
	{
	    cin>>m;

	    for(i=0; i<m; i++) cin>>num1[i]>>num2[i];

	    num1[i]='\0';
	    num2[i]='\0';

	    reverse(num1,m);
	    reverse(num2,m);

	    carry=0;

	    for(i=0; i<m; i++)
	    {
	        carry+=num1[i]+num2[i]-2*'0';
	        num1[i]=carry%10+'0';
	        carry/=10;
	    }
	    num1[i]='\0';

	    reverse(num1,m);

	    if(first) first=false;
	    else cout<<endl;

	    puts(num1);

	    n--;
	}

	return 0;
}
