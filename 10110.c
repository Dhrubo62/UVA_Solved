/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 10110
*/

# include <stdio.h>
# include <math.h>

int check_root(long num)
    {
        long root=(long)sqrt((double) num);
        return root*root==num;
    }

int main(void)
	{
		long num;
		while(scanf("%ld",&num)!=EOF && num)
            {
                if(check_root(num))
                    printf("yes\n");
                else
                    printf("no\n");

            }

		return 0;
	}
