/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11713
*/

# include <iostream>
# include <cstdio>
# include <cstring>
# include <cmath>
# include <cstdlib>
# include <algorithm>

using namespace std;

int vowel(char a)
{
  if(a=='a'||a=='e'||a=='i'||a=='o'||a=='u')
    return 1;
  else
    return 0;
}

int main(void)
{
  int t;
  cin>>t;
  getchar();
  while(t)
    {
      char str1[1000000],str2[1000000];

      gets(str1);
      gets(str2);

      int len1=strlen(str1),len2=strlen(str2);

      if(len1!=len2)
        cout<<"No\n";
      else
        {
          int i;
          for(i=0; i<len1; i++)
            {
              if(str1[i]!=str2[i])
                {
                  if(!(vowel(str1[i]) && vowel(str2[i])))
                    break;
                }
            }
          if(i==len1)
            cout<<"Yes\n";
            else
            cout<<"No\n";
        }

      t--;
    }

  return 0;
}
