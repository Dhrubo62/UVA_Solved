/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11946 - "Code Number"
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
	string rep="OISEASGTBP";
    int cs,i;
    char str[100];

    cin>>cs;
    getchar();

    while(gets(str))
    {
        for(i=0; str[i]; i++)
        {
            if(str[i]>='0' && str[i]<='9')
            {
                if(str[i]=='2')
                {
                    if(!i || str[i-1]==' ') str[i]='Z';
                    else str[i]='S';
                }
                else str[i]=rep[str[i]-'0'];;
            }
        }

        puts(str);
    }

	return 0;
}
