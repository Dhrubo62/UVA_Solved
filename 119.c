/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch
Problem: UVA 119
*/

# include <stdio.h>
# include <string.h>

int main(void)
{
  char name[15][20];
  int take[15],give[15],people,first=1;

  while(scanf("%d", &people) != EOF)
    {
      int i,t,j,amount,divide;
      char temp[12];

      /*inputing names of members and initializing accounts*/
      for(i=0; i<people; i++)
        {
          scanf("%s", name[i]);
          take[i]=give[i]=0;
        }

      /*inputing exchange datas*/
      for(i=0; i<people; i++)
        {
          /*inputing name*/
          scanf("%s", temp);
          for(j=0; j<people; j++)
            {
              if(!strcmp(temp,name[j]))
                {
                  t=j;
                  break;
                }
            }

          /*inputing amount and divide*/
          scanf("%d %d", &amount, &divide);
          give[t] += amount;
          if(amount && !divide)
            give[t] -= amount;
          else if(!amount && divide)
            {
              char del[12];
              for(j=0; j<divide; j++)
                {
                  scanf("%s", del);
                  del[0]='\0';
                }
            }
          else if(amount && divide)
            {
              int crnt_amount=amount/divide,k;
              int mod=amount%divide;
              take[t] += mod;
              char taker[12];
              for(j=0; j<divide; j++)
                {
                  scanf("%s", taker);
                  for(k=0; k<people; k++)
                    {
                      if(!strcmp(taker,name[k]))
                        take[k]+=crnt_amount;
                    }
                }

            }

        }

      if(!first)
        printf("\n");
      else
        first=0;

      for(i=0; i<people; i++)
        printf("%s %d\n",name[i],take[i]-give[i]);
    }

  return 0;
}
