/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 10334 - "Ray Through Glasses"
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
  char temp[10000];
  int i,len=strlen(p);

  for(i=0; i<len; i++)
    temp[i]=p[len-i-1];
  temp[i]='\0';

  strcpy(p,temp);
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

void add(char *one, char *two, char *result)
{
  char f[1000],s[1000],tr[1000];


  strcpy(f,one);
  strcpy(s,two);

  reverse(f);
  reverse(s);
  tr[0]='\0';
  int len=strlen(f);
  add_zero(len-strlen(s),s);

  int carry=0,i,res=0;
  for(i=0; i<len; i++)
    {
      res = f[i] + s[i] - 2*'0' + carry;
      tr[i] = res%10 + '0';
      carry = res/10;
    }

  if(carry)
    tr[i++] = carry + '0';

  tr[i]='\0';

  reverse(tr);
  strcpy(result,tr);
}

char numf[1001][215];
int i,num;

void fibonacchi_pre_gen(void)
{
  strcpy(numf[0],"1");
  strcpy(numf[1],"2");

  for(i=2; i<1001; i++)
    {
      add(numf[i-1],numf[i-2],numf[i]);
    }
}

int main(void)
{
  fibonacchi_pre_gen();

  while(cin >> num)
    {
      cout << numf[num] << endl;
    }

  return 0;
}
