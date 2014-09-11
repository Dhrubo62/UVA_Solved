/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 10530 - "Guessing Game"
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
	char command[100];
	int value,low_limit,high_limit;
	bool low=false,high=false;

	while(cin>>value && value)
	{
	    getchar();
	    gets(command);
	    if(!strcmp(command,"right on"))
	    {
	        if(low && !high)
	        {
	            if(value>low_limit)
	            cout<<"Stan may be honest"<<endl;
	            else
	            cout<<"Stan is dishonest"<<endl;
	        }
	        else if(!low && high)
	        {
	            if(value<high_limit)
                cout<<"Stan may be honest"<<endl;
	            else
	            cout<<"Stan is dishonest"<<endl;
            }
            else if(low && high)
            {
                if(value>low_limit && value<high_limit)
                cout<<"Stan may be honest"<<endl;
	            else
	            cout<<"Stan is dishonest"<<endl;
            }
            else if(!low && !high)
            {
                cout<<"Stan may be honest"<<endl;
            }

            low=high=false;
	    }
	    else if(!strcmp(command,"too low"))
	    {
	        if(!low)
	        {
	            low_limit=value;
	            low=true;
	        }
	        else
	        {
	            if(value>low_limit)
	            low_limit=value;
	        }
	    }
	    else if(!strcmp(command,"too high"))
	    {
	        if(!high)
	        {
	            high_limit=value;
	            high=true;
	        }
	        else
	        {
	            if(value<high_limit)
	            high_limit=value;
	        }
	    }
	}

	return 0;
}
