/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 12700 - "Banglawash"
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
	char ch;
	int c,csn=0,n,b,w,a,t,p;

	cin>>c;
	while(csn<c)
	{
	    b=w=a=t=p=0;

	    cin>>n;
	    while(n)
	    {
	        cin>>ch;
            switch(ch)
            {
                case 'B':
                b++;
                p++;
                break;

                case 'W':
                w++;
                p++;
                break;

                case 'A':
                a++;
                break;

                default:
                t++;
                p++;
            }
            n--;
	    }

	    printf("Case %d: ",++csn);
	    if(!p)  printf("ABANDONED\n");
	    else if(b==p) printf("BANGLAWASH\n");
	    else if(w==p) printf("WHITEWASH\n");
	    else if(b>w)  printf("BANGLADESH %d - %d\n",b,w);
	    else if(w>b)  printf("WWW %d - %d\n",w,b);
	    else printf("DRAW %d %d\n",b,t);
	}

	return 0;
}
