/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 10189
*/

# include <stdio.h>

int main(void)
{
  char field[500][500];
  int n,m,c=0,first=1;

  while(scanf("%d %d",&n,&m)!=EOF && n && m)
    {
      getchar();
      c++;

      int i,j,k,l,count;
      for(i=0; i<n; i++)
        gets(field[i]);

      for(i=0; i<n; i++)
        {
          for(j=0; j<m; j++)
            {
              if(field[i][j]=='.')
                {
                  count=0;
                  for(k=i-1; k<=i+1; k++)
                    {
                      for(l=j-1; l<=j+1; l++)
                        {
                          if(k>=0 && l>=0 && k<n && l<m)
                            if(field[k][l]=='*')
                              count++;
                        }
                    }
                  field[i][j]=count+48;
                }
            }
        }

      if(first)
        first=0;
      else if(!first)
        printf("\n");

      printf("Field #%d:\n",c);

      for(i=0; i<n; i++)
        puts(field[i]);
    }

  return 0;
}
