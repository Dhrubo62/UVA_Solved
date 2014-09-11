/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11764
*/

# include <iostream>
# include <cstdio>

using namespace std;

int main(void)
  {
	int i=0,t;
	cin >> t;

	while(i<t)
	{
	    int n,j,array[1000];
	    cin >> n;

	    for(j=0;j<n;j++)
	    cin >> array[j];

	    int high=0,low=0;

	    for(j=0;j<n-1;j++)
	    {
	        if(array[j]<array[j+1])
	        high++;
	        else if(array[j]>array[j+1])
	        low++;
	    }

	    cout<<"Case "<<i+1<<": "<<high<<' '<<low<<endl;

	    i++;
	}

	return 0;
  }
