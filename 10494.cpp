/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 10494 - "If We Were a Child Again"
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
	char num[100000],op,result[100000],temp[100];
	unsigned long long n,rem,res;
	int len,i,j;

	while(cin>>num>>op>>n)
	{
	    len=strlen(num);

        rem=0; result[0]='\0';
	    for(i=0; i<len; i++)
	    {
	        rem = rem*10+num[i]-'0';
	        sprintf(temp,"%c",rem/n+'0'); strcat(result,temp);
	        rem %= n;
        }

        if(op=='%') cout<<rem<<endl;
        else
        {
            len=strlen(result);
            for(i=0; result[i]=='0' && i<len; i++);
            if(i==len) cout<<"0"<<endl;
            else
            {
                for(j=i; j<len; j++) cout<<result[j];
                cout<<endl;
            }
        }
	}

	return 0;
}
