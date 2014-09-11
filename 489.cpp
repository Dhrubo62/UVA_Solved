/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA 489
*/

# include <stdio.h>
# include <string.h>

int main(void)
{
  char solve[1000000],guess[1000000], *post[]= {"You chickened out.\n","You win.\n","You lose.\n"};
  int slv,gse,round,total,found,i,j,hang,score;

  while(scanf("%d",&round)==1 && round!=-1)
    {
      getchar();

      //input
      gets(solve);
      total=slv=strlen(solve);
      gets(guess);
      gse=strlen(guess);

      //judging
      hang=0;
      score=0;
      for(i=0; i<gse; i++)
        {
          found=0;

          for(j=0; j<slv; j++)
            if(solve[j]==guess[i])
              {
                solve[j]=' ';
                found++;
                total--;
              }

          if(!found)
            hang++;

          if(!total)
            {
              score=1;
              break;
            }

          if(hang==7)
            {
              score=2;
              break;
            }
        }

      printf("Round %d\n%s",round,post[score]);
    }

  return 0;
}
