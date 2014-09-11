/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch
Problem: UVA - 409
*/

# include <stdio.h>
# include <string.h>
# include <ctype.h>

int search(char *key,char *line)
{
  int found,count=0,i,j,k,lenline=strlen(line),lenkey=strlen(key);

  for(i=0; i<lenline; i++)
    {
      if(line[i]==key[0] && (line[i-1]<'a' || line[i-1]>'z') && (line[i-1]<'A' || line[i-1]>'Z'))
        {
          found=0;
          for(j=0,k=i; j<lenkey; j++,k++)
            {
              if(key[j]==line[k]) found=1;
              else
                {
                  found=0;
                  break;
                }
            }
          if(found)
            {
              if((line[k]<'a' || line[k]>'z') && (line[k]<'A' || line[k]>'Z'))
                found=1;
              else
                {
                  found=0;
                }
            }
          if(found) count++;
        }
    }
  return count;
}

int main(void)
{
  int k,e,i,j,total[25],max,maxlist[25],count,num=0;
  char keyword[25][1000],keyword_copy[25][1000],excuse[25][10000];

  while(scanf("%d %d",&k,&e) != EOF)
    {
      num++;
      getchar();

      for(i=0; i<k; i++)
        {
            gets(keyword[i]);
            strcpy(keyword_copy[i],keyword[i]);
            for(j=0;keyword_copy[i][j];j++)
            keyword_copy[i][j]=toupper(keyword_copy[i][j]);
        }


      for(i=0; i<e; i++)
        gets(excuse[i]);

   /* for(i=0;i<k;i++)
    puts(excuse[i]);*/
      for(i=0; i<25; i++)
        total[i]=0;

      for(i=0; i<e; i++)
        {
          for(j=0; j<k; j++)
            {
              total[i]+=search(keyword[j],excuse[i]);
            }
        }

        for(i=0; i<e; i++)
        {
          for(j=0; j<k; j++)
            {
              total[i]+=search(keyword_copy[j],excuse[i]);
            }
        }

        max=total[0];
        for(i=1;i<e;i++)
        {
            if(total[i]>max) max=total[i];
        }

        count=0;
        for(i=0,j=0;i<e;i++)
        {
            if(total[i]==max)
            {
                maxlist[j]=i;
                j++;
                count++;
            }
        }

        printf("Excuse Set #%d\n",num);
        for(i=0;i<count;i++)
        puts(excuse[maxlist[i]]);
        printf("\n");

    }

  return 0;
}
