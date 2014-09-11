/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11278 - "ONE-HANDED TYPIST"
*/

# include <iostream>
# include <cstdio>
# include <cstring>
# include <cmath>
# include <cstdlib>
# include <algorithm>
# include <cctype>

using namespace std;

char ori[1000000] = "4567890-=qwertyuiop[]asdfghjkl;'zxcvbnm,./!@#$%^&*()_+QWERTYUIOP{}ASDFGHJKL:\"ZXCVBNM<>?";
char rep[1000000] = "qjlmfp/[]456.orsuyb;=789aehtdck-0zx,inwvg'!@#QJLMFP?{}$%^>ORSUYB:+&*(AEHTDCK_)ZX<INWVG\"";

int main(void)
{
    char line[1000000];
    int len_ori = strlen(ori);

    while(gets(line))
    {
        int len_line = strlen(line),i,j;

        for(i=0; i<len_line; i++)
        {
            for(j=0; j<len_ori; j++)
            {
                if(line[i] == ori[j])
                {
                    line[i] = rep[j];
                    break;
                }
            }
        }

        puts(line);
    }

	return 0;
}
