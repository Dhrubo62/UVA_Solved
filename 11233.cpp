/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11233
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
  int l,n,i,j,len;
  char forms[1000][2][1000],word[1000];

  cin >> l >> n;

  for(i=0; i<l; i++)
    {
      cin >> forms[i][0] >> forms[i][1];
    }

  for(i=0; i<n; i++)
    {
      cin >> word;
      len = strlen(word);

      for(j=0; j<l; j++)
        if(!strcmp(word,forms[j][0]))
          {
            cout << forms[j][1] << endl;
            break;
          }
      if(j<l)
        continue;

      if(word[len-1]=='y' && word[len-2]!='a' && word[len-2]!='e' && word[len-2]!='i' && word[len-2]!='o' && word[len-2]!='u')
        {
          for(j=0; j<len-1; j++)
            cout << word[j];

          printf("ies\n");
        }
      else if(word[len-1]=='o' || word[len-1]=='s' || word[len-1]=='x' || (word[len-1]=='h' && (word[len-2]=='c' || word[len-2]=='s')))
        printf("%ses\n",word);
      else
        printf("%ss\n",word);
    }

  return 0;
}
