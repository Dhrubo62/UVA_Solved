/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11743 - "Credit Check"
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

int dbl,non_dbl;

int sum_digits(int x)
{
    int t=0;

    while(x)
    {
        t += x%10;
        x /= 10;
    }

    return t;
}

void process(char *p)
{
    int temp;

    //first digit
    temp = p[0] - '0';
    temp *= 2;
    dbl += sum_digits(temp);

    //third digit
    temp = p[2] - '0';
    temp *= 2;
    dbl += sum_digits(temp);

    //non double
    non_dbl += p[1]+p[3]-2*'0';
}

int main(void)
{
	char str[10];
	int t;

	cin>>t;
	getchar();
	while(t)
	{
        dbl=non_dbl=0;

        for(int i=0; i<4; i++)
        {
            cin>>str;

            process(str);
        }

        (dbl+non_dbl)%10 ? cout<<"Invalid"<<endl : cout<<"Valid"<<endl;

	    t--;
	}

	return 0;
}
