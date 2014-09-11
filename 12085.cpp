/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 12085 - "Mobile Casanova"
*/

// ----------------- C headers
# include <cstdio>
# include <cstring>
# include <cmath>
# include <cstdlib>
# include <cctype>

// ----------------- C++ headers
# include <iostream>
# include <string>
# include <algorithm>
# include <vector>
# include <queue>

//------------------ Movements
/*int dx[]={1,-1,0,0}, dy[]={0,0,1,-1};*/ // 4 way movement
/*int dx[]={1,0,-1,0,1,-1,1,-1}, dy[]={0,1,0,-1,1,1,-1,-1};*/ // 8 way movement

using namespace std;

char number[100],first[100],last[100];
bool only_one;
int n,i,total;

void print_sequence()
{
    bool same=true;
    if(total==1) cout<<first<<endl;
    else
    {
        cout<<first<<"-";
        int len=strlen(last),x;
        for(x=0; x<len; x++)
        {
            if(first[x]!=last[x]) same=false;
            if(!same) cout<<last[x];
        }
        cout<<endl;
    }
}

int main()
{
	int csn=0;

	while(cin>>n && n)
	{
	    printf("Case %d:\n",++csn);

	    for(i=0; i<n; i++)
	    {
	        cin>>number;

	        if(!i) //very first in the sequence
	        {
	            strcpy(first,number);
	            strcpy(last,number);
	            total=1;
	        }
	        else
	        {
	            if(atol(number)==atol(last)+1) //sequence has continued
	            {
	                strcpy(last,number);
	                total++;
	            }
	            else
	            {
	                print_sequence();
	                strcpy(first,number);
                    strcpy(last,number);
                    total=1;
	            }
	        }
	    }
	    print_sequence();
	    cout<<endl;
	}

	return 0;
}
