/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 444 - "Encoder and Decoder"
*/

# include <iostream>
# include <cstdio>
# include <cstring>
# include <cmath>
# include <cstdlib>
# include <algorithm>
# include <cctype>

using namespace std;

void reverse(char *p)
{
  char temp[10000];
  int i,len=strlen(p);

  for(i=0; i<len; i++)
    temp[i]=p[len-i-1];
  temp[i]='\0';

  strcpy(p,temp);
}

int main(void)
{
	char str[1000000];

	while(gets(str))
	{
	    if(str[0] >= '0' && str[0] <= '9')
	    {
            char output[1000000],temp[1000];
	        output[0] = '\0';
	        int i, j, len = strlen(str), number;

            reverse(str);

            for(i=0; i<len; )
            {
                number = 0;

                if(str[i] == '1')
                {
                    for(j=i; j<i+3; j++)
                    {
                        number = number*10 + str[j] - '0';
                    }

                    sprintf(temp,"%c",number);
                    strcat(output,temp);

                    i += 3;
                }
                else
                {
                    for(j=i; j<i+2; j++)
                    {
                        number = number*10 + str[j] - '0';
                    }

                    sprintf(temp,"%c",number);
                    strcat(output,temp);

                    i += 2;
                }

            }

            puts(output);
	    }
	    else
	    {
	        char output[1000000],temp[1000];
	        output[0] = '\0';
	        int i, len = strlen(str);

	        for(i=0; i<len; i++)
	        {
	            sprintf(temp,"%d",str[i]);
	            strcat(output,temp);
	        }

	        reverse(output);
	        puts(output);
	    }
	}

	return 0;
}
