/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 10945 - "Mother Bear"
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
	string str,res[2]={"Uh oh..","You won't be eaten!"};
    char c_str[10000];
    bool palin;

    while(gets(c_str) && strcmp(c_str,"DONE"))
    {
        //converting into same case
        for(int i=0; c_str[i]; i++) c_str[i]=toupper(c_str[i]);

        //converting the C-String into a String
        str=c_str;
        int len=str.size();

        //Deleting non alphabetic characters
        for(int i=0; i<len; )
        {
            if(!(str[i]>='A' && str[i]<='Z'))
            {
                str.erase(i,1);
                len--;
            }
            else i++;
        }

        //checking palindrome state
        palin = true;
        for(int i=0; i<len/2; i++)
        {
            if(str[i] != str[len-i-1])
            {
                palin = false;
                break;
            }
        }

        //result
        cout<<res[palin]<<endl;
    }

	return 0;
}
