/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 10082
*/

# include <stdio.h>

int main(void)
{
	char original[]={'`','1','2','3','4','5','6','7','8','9','0','-',
                     'Q','W','E','R','T','Y','U','I','O','P','[',']',
                     'A','S','D','F','G','H','J','K','L',';',
                     'Z','X','C','V','B','N','M',',','.'};

    char represent[]={'1','2','3','4','5','6','7','8','9','0','-','=',
                      'W','E','R','T','Y','U','I','O','P','[',']','\\',
                      'S','D','F','G','H','J','K','L',';','\'',
                      'X','C','V','B','N','M',',','.','/'};

    char text[1000];
    int i,j;

    while(gets(text))
    {
        for(i=0;text[i];i++)
        {
            for(j=0;represent[j];j++)
            {
                if(text[i]==represent[j])
                {
                    text[i]=original[j];
                    break;
                }
            }
        }
        puts(text);
    }

	return 0;
}
