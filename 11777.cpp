/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11777
*/

# include <iostream>
# include <cstdio>
# include <algorithm>

using namespace std;

int compare(int a,int b)
{
  return a>b;
}

int main(void)
{
  int i=0,t;
  cin>>t;
  while(i<t)
    {
      double term1,term2,final,att,cls[3],total=0;
      cin>>term1>>term2>>final>>att>>cls[0]>>cls[1]>>cls[2];

      total+=(term1+term2+final+att);

      sort(cls,cls+3,compare);

      total+=((cls[0]+cls[1])/2);

      printf("Case %d: ",++i);

      if(total>=90)
        cout<<'A'<<endl;
      else if(total>=80 && total<90)
        cout<<'B'<<endl;
      else if(total>=70 && total<80)
        cout<<'C'<<endl;
      else if(total>=60 && total<70)
        cout<<'D'<<endl;
      else
        cout<<'F'<<endl;
    }

  return 0;
}
