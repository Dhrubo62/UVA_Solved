/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 10324 - "Zeros and Ones"
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
	char str[2000000];
	int min,max,temp,len,i,n,csn=0;

	while(gets(str) && strcmp(str,""))
	{
        cin>>n;
        getchar();

        len=strlen(str);

        printf("Case %d:\n",++csn);

        while(n)
        {
            cin>>min>>max;
            getchar();

            if(max<min)
            {
                temp=max;
                max=min;
                min=temp;
            }

            if(min<0 || max>=len)
            {
                cout<<"No"<<endl;
            }
            else
            {
                for(i=min+1; i<=max; i++)
                {
                    if(str[i]!=str[min])
                    break;
                }

                if(i>max)
                cout<<"Yes"<<endl;
                else
                cout<<"No"<<endl;
            }

            n--;
        }
	}

	return 0;
}
