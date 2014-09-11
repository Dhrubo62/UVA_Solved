/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 10035
*/

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

void swap(char *one,char *two)
{
  char temp[15];
  strcpy(temp,one);
  strcpy(one,two);
  strcpy(two,temp);
}

int main(void)
{
  char num1[15], num2[15];

  while(scanf("%s %s",num1,num2))
    {
      if(!atol(num1) && !atol(num2)) break;

      if(atol(num1) < atol(num2))
        swap(num1,num2);

      int one=strlen(num1),two=strlen(num2);

      int i,j,result=0,down=0,carry=0,count=0;
      for(i=one-1,j=two-1; i>=0; i--)
        {
          if(j>=0)
            result = num1[i] - 48 + num2[j] - 48 + carry;
          else
            result = num1[i] - 48 + carry;

          down = result%10;
          carry = result/10;
          if(carry) count++;
          if(j>=0) j--;
        }

      if(count==0)
        printf("No carry operation.\n");
      else if(count==1)
        printf("1 carry operation.\n");
      else
        printf("%d carry operations.\n",count);


    }

  return 0;
}
