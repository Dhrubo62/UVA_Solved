/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 10327
*/

# include <stdio.h>

void flip(int *x, int *y)
    {
        int temp=*x;
        *x=*y;
        *y=temp;
    }

int main(void)
{
	int num;

	while(scanf("%d", &num)!=EOF)
	{
        int *array,i,j,count=0;
        array=(int *)malloc(num*sizeof(int));
        for(i=0;i<num;i++)
            scanf("%d", &array[i]);

        for(i=0;i<num-1;i++)
            {
                for(j=0;j<num-1-i;j++)
                    {
                        if(array[j]>array[j+1])
                            {
                                flip(&array[j], &array[j+1]);
                                count++;
                            }
                    }
            }

        printf("Minimum exchange operations : %d\n",count);
	}

	return 0;
}
