/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 713 - "Adding Reversed Numbers"
*/

# include <iostream>
# include <cstdio>
# include <cstring>
# include <cmath>
# include <cstdlib>
# include <algorithm>
# include <cctype>

using namespace std;

void reverse(char *p)
{
  int len=strlen(p);
  char c;

  for(int i=0; i<len/2; i++)
    {
      c = p[i];
      p[i] = p[len-i-1];
      p[len-i-1] = c;
    }
}

void kill_trailing_zero(char *p)
{
  int len=strlen(p);

  for(int i=len-1; i>=1; i--)
    {
      if(p[i]=='0')
        p[i] = '\0';
      else break;
    }
}

void add_zero(char *p,int n) //for a reversed number string
{
  int len=strlen(p);

  while(n)
    {
      p[len++]= '0';

      n--;
    }

  p[len]='\0';
}

void swap(char *a,char *b)
{
  char t[1000];
  strcpy(t,a);
  strcpy(a,b);
  strcpy(b,t);
}

void add(char *f,char *s,char *r)
{
  char first[1000],second[1000],result[1000];

  strcpy(first,f);
  strcpy(second,s);

  reverse(first);
  reverse(second);

  if(strlen(second) > strlen(first))
    swap(second,first);

  int len=strlen(first),carry=0,i;

  add_zero(second,len-strlen(second));

  for(i=0; i<len; i++)
    {
        carry += first[i] + second[i] - 2*'0';
        result[i] = carry%10 + '0';
        carry /= 10;
    }

    if(carry) result[i++] = carry + '0';

    result[i] = '\0';

    reverse(result);

    strcpy(r,result);
}

int main(void)
{
  char str1[1000],str2[1000];
  int n;

  cin >> n;
  while(n)
  {
      cin >> str1 >> str2;

      reverse(str1);
      kill_trailing_zero(str1);

      reverse(str2);
      kill_trailing_zero(str2);

      add(str1,str2,str1);
      kill_trailing_zero(str1);
      reverse(str1);

      puts(str1);

      n--;
  }

  return 0;
}
