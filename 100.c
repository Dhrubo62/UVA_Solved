/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch
Problem: UVA - 100
*/

# include <stdio.h>

long cycle_length(long n)
    {
        long count=0;
        while(1)
            {
                count++;
                if(n==1)
                    break;
                if(n%2) n = 3*n+1;
                else n = n/2;
            }

        return count;
    }

int main(void)
	{
        long num1,num2,max,temp,i,temp1,temp2;

        while(scanf("%ld %ld", &num1, &num2)!=EOF)
            {
                max=temp=0;
                if(num1<num2)
                    {
                        temp1=num1;
                        temp2=num2;
                    }
                else
                    {
                        temp1=num2;
                        temp2=num1;
                    }
                for(i=temp1;i<=temp2;i++)
                    {
                        temp=cycle_length(i);
                        if(temp>max)
                            max=temp;
                    }

                printf("%ld %ld %ld\n",num1,num2,max);
            }

		return 0;
	}
