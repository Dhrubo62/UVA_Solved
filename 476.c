/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA 476
*/

# include <stdio.h>

int main(void)
{
  double figure[100][100];
  int f=0;
  char first;
  while(scanf("%c",&first)==1)
    {
      if(first=='r')
        {
          scanf("%lf %lf %lf %lf",&figure[f][0],&figure[f][1],&figure[f][2],&figure[f][3]);
          getchar();
          f++;
        }
      else
        break;
    }

  int point=0;

  if(first=='*')
    {
      double x,y;
      while(scanf("%lf %lf",&x,&y)==2)
        {
          if(x==9999.9 && y==9999.9)
            break;

          int found=0,i;
          point++;

          for(i=0; i<f; i++)
            {
              if(x>=figure[i][0] && x<=figure[i][2] && y<=figure[i][1] && y>=figure[i][3])
                {
                  printf("Point %d is contained in figure %d\n",point,i+1);
                  found++;
                }
            }

          if(!found)
            printf("Point %d is not contained in any figure\n",point);
        }
    }

  return 0;
}
