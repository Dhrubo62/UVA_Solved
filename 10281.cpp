/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 10281 - "Average Speed"
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
	char str[1000];
	double last_time=0,present_time=0,speed=0,total=0;

	while(gets(str))
	{
	    present_time=(((str[0]-'0')*10+(str[1]-'0'))*3600) + (((str[3]-'0')*10+(str[4]-'0')))*60 + ((str[6]-'0')*10+(str[7]-'0'));

        total += (present_time-last_time)*(speed/3600);
        last_time = present_time;

	    if(strlen(str)==8)
	    {
	        printf("%s %0.2lf km\n",str,total);
	    }
	    else
	    {
	        speed=0;
	        for(int i=9; str[i]; i++)
	        {
	            speed = speed*10 + str[i]-'0';
	        }
	    }
	}

	return 0;
}
