/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 10070
*/

# include <stdio.h>

char year[1000];

int remainder(int num)
{
    int i, temp=0;
    for(i=0;year[i];i++)
    {
        temp=temp*10+year[i]-'0';
        temp%=num;
    }
    return temp;
}

int main(void)
{
    int first=1;

    while(gets(year)!=NULL)
    {
        if(!first) printf("\n");

        first=0;

        int print=0,leap_year=0;
        if((!remainder(4) && remainder(100)) || !remainder(400))
        {
            printf("This is leap year.\n");
            print=1;
            leap_year=1;
        }
        if(!remainder(15))
        {
            printf("This is huluculu festival year.\n");
            print=1;
        }
        if(!remainder(55) && leap_year)
        {
            printf("This is bulukulu festival year.\n");
            print=1;
        }
        if(!print) printf("This is an ordinary year.\n");
    }

	return 0;
}
