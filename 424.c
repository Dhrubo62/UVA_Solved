/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch
Problem: UVA 424
*/

# include <stdio.h>
# include <string.h>
# include <stdlib.h>

void reverse(char *p)
{
  char temp[10000];
  int i,len=strlen(p);

  for(i=0; i<len; i++)
    temp[i]=p[len-i-1];
  temp[i]='\0';

  strcpy(p,temp);
}

void kill_zero(char *p)
{
  int len=strlen(p);
  len--;
  while(1)
    {
      if(p[len]=='0')
        {
          p[len]='\0';
          len--;
        }
      else
        break;
    }
}

void add_zero(int n,char *p)
{
  int len=strlen(p);
  while(n)
    {
      p[len++]='0';
      n--;
    }
  p[len]='\0';
}

void swap(char *one,char *two)
{
  char temp[10000];
  strcpy(temp,one);
  strcpy(one,two);
  strcpy(two,temp);
}

void add(char *_1,char *_2,char *r)
{
  char one[10000],two[10000],res[10000];
  strcpy(one,_1);
  strcpy(two,_2);
  if(strlen(one)<strlen(two))
    swap(one,two);

  int len=strlen(one);
  if(len!=strlen(two))
    add_zero((len-strlen(two)),two);

  int i,result=0,carry=0;
  for(i=0; i<len; i++)
    {
      result=one[i]-48+two[i]-48+carry;
      res[i]=(result%10)+48;
      carry=result/10;
    }
  if(carry)
    res[i++]=carry+48;
  res[i]='\0';

  strcpy(r,res);
}

int main(void)
{
  char num[10000],result[10000];
  int first=1;

  while(gets(num))
    {
      if(strlen(num)==1 && !atoi(num))
        break;

      reverse(num);
      kill_zero(num);

      if(first)
        {
          strcpy(result,num);
          first=0;
        }
        else
        {
            add(num,result,result);
        }
    }

    reverse(result);
    puts(result);

  return 0;
}
