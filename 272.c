/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch
Problem: UVA 272
*/

# include <stdio.h>
# include <string.h>

int main(void)
  {
	char string[1000];
	int first=1;

	while(gets(string))
	{
	    int i,j,size=strlen(string);
	    for(i=0;i<size;i++ )
	    {
	        if(string[i]=='"')
	        {
	            for(j=size;j>i;j--)
                    string[j]=string[j-1];
                string[size+1]='\0';

                if(first)
                {
                    string[i]=string[i+1]='`';
                    first=0;
                }
                else
                {
                    string[i]=string[i+1]='\'';
                    first=1;
                }
                size++;
	        }
	    }
	    puts(string);
	}

	return 0;
  }
