/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 12503
*/

# include <iostream>
# include <cstdio>
# include <cstring>
# include <cmath>
# include <cstdlib>
# include <algorithm>

using namespace std;

char now[1000],as[1000];

struct
{
    char cmd[1000];
    int c;
} ins[1000];

int main(void)
{
	int t;

	cin >> t;
	getchar();

	while(t)
	{
	    int n,i=0,pos=0;

	    cin >> n;
	    getchar();

	    while(i<n)
	    {
	        cin >> ins[i].cmd;

	        if(!strcmp(ins[i].cmd,"SAME"))
	        {
	            cin >> as >> ins[i].c;
	        }

            strcpy(now,ins[i].cmd);

            int index=ins[i].c-1;
            while(1)
            {
                if(!strcmp(now,"SAME"))
                strcpy(now,ins[index].cmd);

                if(!strcmp(now,"LEFT") || !strcmp(now,"RIGHT"))
                break;
                else
                index=ins[index].c-1;
            }

            if(!strcmp(now,"LEFT"))
            pos--;
            else if(!strcmp(now,"RIGHT"))
            pos++;

            i++;
	    }

	    cout << pos << endl;

	    t--;
	}

	return 0;
}
