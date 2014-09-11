/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11219
*/

# include <iostream>
# include <cstdio>

using namespace std;

int main(void)
{
  int i=0,t,a,b,c,d,e,f,age;

  cin>>t;
  while(i<t)
    {
      scanf("%d/%d/%d",&a,&b,&c);
      scanf("%d/%d/%d",&d,&e,&f);

      printf("Case #%d: ",++i);

      if(f>c || (f==c && e>b) || (f==c && e==b && d>a))
        {
          printf("Invalid birth date\n");
          continue;
        }
      else if(f<c)
        {
          age=c-f-1;

          if(b>e || (b==e && a>=d))
            age++;
        }
      else if(f==c)
        age=0;

        if(age>130)
        printf("Check birth date\n");
        else
        printf("%d\n",age);
    }

  return 0;
}
