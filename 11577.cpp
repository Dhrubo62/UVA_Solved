/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11577 - "Letter Frequency"
*/

# include <iostream>
# include <cstdio>
# include <cstring>
# include <cmath>
# include <cstdlib>
# include <algorithm>
# include <cctype>

using namespace std;

int main(void)
{
  char str[500];
  int n,cnt[26],i;

  cin >> n;
  getchar();

  while(n)
    {
      gets(str);

      int len=strlen(str);

      for(i=0; i<26; i++) cnt[i]=0;

      for(i=0; i<len; i++)
        {
          str[i] = tolower(str[i]);

          if(str[i]>='a' && str[i]<='z')
            cnt[str[i] - 'a']++;
        }

      int max = cnt[0];
      for(i=1; i<26; i++)
        {
          if(cnt[i]>max)
            max = cnt[i];
        }

      for(i=0; i<26; i++)
        if(cnt[i] == max)
          printf("%c",i+'a');

      cout << endl;

      n--;
    }

  return 0;
}
