/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch
Problem: UVA 401
*/

# include <stdio.h>
# include <string.h>

int main(void)
{
  char ori[]= {'A','E','H','I','J','L','M','O','S','T','U','V','W','X','Y','Z','1','2','3','5','8'};
  char mir[]= {'A','3','H','I','L','J','M','O','2','T','U','V','W','X','Y','5','1','S','E','Z','8'};
  char str_1[1000],str_2[1000];
  int i,j,len,len_ref,mirror,palin;

  while(gets(str_1))
    {
      len=strlen(str_1);
      len_ref=strlen(ori);

      for(i=0; i<len; i++)
        {
          if(str_1[i]=='0')
            str_1[i]=='O';
        }

      palin=1;

      for(i=0; i<(len/2); i++)
        {
          if(str_1[i]!=str_1[len-1-i])
            {
              palin=0;
              break;
            }
        }

      mirror=1;

      for(i=0; i<len; i++)
        {
          for(j=0; j<len_ref; j++)
            {
              if(str_1[i]==ori[j])
                {
                  str_2[i]=mir[j];
                  break;
                }
            }

          if(j==len_ref)
            {
              mirror=0;
              break;
            }
        }

      if(mirror)
        {
          for(i=0; i<len; i++)
            {
              if(str_1[i]!=str_2[len-1-i])
                {
                  mirror=0;
                  break;
                }
            }
        }

      if(!palin && !mirror)
        printf("%s -- is not a palindrome.\n\n",str_1);
      else if(palin && !mirror)
        printf("%s -- is a regular palindrome.\n\n",str_1);
      else if(!palin && mirror)
        printf("%s -- is a mirrored string.\n\n",str_1);
      else if(palin && mirror)
        printf("%s -- is a mirrored palindrome.\n\n",str_1);
    }

  return 0;
}
