/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 10137 - "The Trip"
*/

# include <iostream>
# include <cstdio>
# include <cstring>
# include <string>
# include <cmath>
# include <cstdlib>
# include <algorithm>
# include <cctype>

using namespace std;

int main(void)
{
	int i,n;
	while(cin>>n && n)
	{
	    double list[1010],ave,total=0.0;
	    for(i=0; i<n; i++)
	    {
	        cin>>list[i]; list[i]*=100.0;
	        total+=list[i];
	    }
	    ave=(int) ((total/n)+0.5);

	    double res1=0.0,res2=0.0;
	    for(i=0; i<n; i++)
	    {
	        if(list[i]>ave) res1+=list[i]-ave;
	        else if(list[i]<ave) res2+=ave-list[i];
	    }

	    printf("$%0.2lf\n",min(res1,res2)/100);
	}

	return 0;
}
