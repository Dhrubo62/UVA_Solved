/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 10789 - "Prime Frequency"
*/

# include <iostream>
# include <cstdio>
# include <cstring>
# include <cmath>
# include <cstdlib>
# include <algorithm>
# include <cctype>

using namespace std;

int prime(int num)
{
  if(num<=1)
    return 0;

  if(num==2)
    return 1;

  if(!(num%2))
    return 0;

  int srt=sqrt(num*1.0);
  for(int i=3; i<=srt; i+=2)
    {
      if(!(num%i))
        return 0;
    }

  return 1;
}

int main(void)
{
  char str[1000000];
  int cnt[70],i,csn=0,n;

  cin>>n;
  getchar();

  while(csn<n)
    {
      gets(str);

      for(i=0; i<70; i++)
        cnt[i]=0;

      int len = strlen(str);

      for(i=0; i<len; i++)
        {
          if(str[i]>='0' && str[i]<='9')
            cnt[str[i]-'0']++;
          else if(str[i]>='A' && str[i]<='Z')
            cnt[str[i]-55]++;
          else if(str[i]>='a' && str[i]<='z')
            cnt[str[i]-61]++;
        }

      printf("Case %d: ",++csn);
      int p=0;

      for(i=0; i<62; i++)
        {
          if(prime(cnt[i]))
            {
              if(i>=0 && i<=9)
                printf("%c",i+'0');
              else if(i>=10 && i<=35)
                printf("%c",i+55);
              else
                printf("%c",i+61);

              p++;
            }
        }

      if(!p)
        printf("empty");

      cout << endl;

    }
  return 0;
}
