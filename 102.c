/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch
Problem: UVA - 102
*/

# include <stdio.h>
# include <string.h>

int main(void)
{
  unsigned long array[3][3];
  unsigned long total[6];
  int peak[3];
  char name[6][5]= {"BGC","BCG","GBC","GCB","CGB","CBG"};



  while(scanf("%lu",&array[0][0])!=EOF)
    {
      int i,j,k;

      for(i=0; i<3; i++)
        {
          if(i==0) k=1;
          else k=0;
          for(j=k; j<3; j++)
            scanf("%lu",&array[i][j]);
        }

      for(i=0; i<6; i++)
        total[i]=0;

      for(i=0; i<6; i++)
        {
          for(j=0; j<3; j++)
            {
              if(name[i][0]==name[0][j])
                peak[0]=j;
              else if(name[i][1]==name[0][j])
                peak[1]=j;
              else if(name[i][2]==name[0][j])
                peak[2]=j;
            }

          for(j=0; j<3; j++)
            {
              for(k=0; k<3; k++)
                {
                  if(peak[j]!=k)
                    total[i]+=array[j][k];
                }
            }
        }
      int min_index=0;
      unsigned long min=total[0];
      for(i=1; i<6; i++)
        {
          if(total[i]<min)
            {
              min=total[i];
              min_index=i;
            }
          else if(total[i]==min)
            {
              if(strcmp(name[i],name[min_index]) < 0)
                {
                  min=total[i];
                  min_index=i;
                }
            }
        }

      printf("%s %lu\n",name[min_index],min);
    }

  return 0;
}

