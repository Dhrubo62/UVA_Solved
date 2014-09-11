/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 10783
*/

# include <iostream>
# include <cstdio>

using namespace std;

void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

int main(void)
  {
	int i=0,t;
	cin>>t;
	while(i<t)
	{
	    int x,y,j,total=0;
	    cin>>x>>y;

	    if(x>y)
	    swap(&x,&y);

	    for(j=x;j<=y;j++)
	    {
	        if(j%2)
	        total+=j;
	    }

	    cout<<"Case "<<++i<<": "<<total<<endl;
	}

	return 0;
  }
