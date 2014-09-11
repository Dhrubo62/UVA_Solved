/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 371 - "Ackermann Functions"
*/

# include <iostream>
# include <cstdio>
# include <cstring>
# include <cmath>
# include <cstdlib>
# include <algorithm>
# include <cctype>

using namespace std;

long long ackermann(long long num)
{
    long long cnt=0;

    while(1)
    {
        if(!(num%2))
        num /= 2;
        else
        num = 3*num +1;

        cnt++;

        if(num <= 1)
        break;
    }

    return cnt;
}

int main(void)
{
	long long num1,num2,i,temp;

	while(cin >> num1 >> num2 && !(!num1 && !num2))
	{
	    long long temp1 = num1, temp2 = num2;

	    if(num1 > num2)
	    {
	        temp = num2;
	        num2 = num1;
	        num1 = temp;
	    }

	    long long max_num=0, max_length=0;

	    for(i=num1; i<=num2; i++)
	    {
	        if(ackermann(i) > max_length)
	        {
	            max_length = ackermann(i);
	            max_num = i;
	        }
	    }

	    printf("Between %lld and %lld, %lld generates the longest sequence of %lld values.\n",num1,num2,max_num,max_length);
	}

	return 0;
}
