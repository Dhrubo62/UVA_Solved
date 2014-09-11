/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 10222
*/

# include <stdio.h>
# include <ctype.h>

int main(void)
{
	char original[]={'`','1','2','3','4','5','6','7','8','9','0',
                     'q','w','e','r','t','y','u','i','o','p','[',
                     'a','s','d','f','g','h','j','k','l',
                     'z','x','c','v','b','n','m',','};

    char represent[]={'2','3','4','5','6','7','8','9','0','-','=',
                      'e','r','t','y','u','i','o','p','[',']','\\',
                      'd','f','g','h','j','k','l',';','\'',
                      'c','v','b','n','m',',','.','/'};

    char text[1000];
    int i,j;

    while(gets(text))
    {
        for(i=0;text[i];i++)
        {
            text[i]=tolower(text[i]);
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
