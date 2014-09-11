/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11470 - "Square Sums"
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
	int n,**m,i,j,k,sum,mid,csn=0;

	while(cin>>n && n)
	{
	    //memory allocation
	    m=(int **)malloc(n*sizeof(int *));
	    for(i=0; i<n; i++) m[i]=(int *)malloc(n*sizeof(int));

	    //input the matrix
	    for(i=0; i<n; i++)
	    {
	        for(j=0; j<n; j++) cin>>m[i][j];
	    }

	    //calculating the sums and printing them
	    printf("Case %d:",++csn);
	    mid = n/2;
	    if(!(n%2)) mid--;
	    for(i=0; i<=mid; i++)
	    {
	        sum=0;
	        for(j=i; j<n-i; j++)
	        {
	            if(j==i || j==n-i-1)
	            {
	                for(k=i; k<n-i; k++)
	                sum += m[j][k];
	            }
	            else
	            {
	                sum += m[j][i];
	                sum += m[j][n-i-1];
	            }
	        }
	        printf(" %d",sum);
	    }
	    cout<<endl;

	    //freeing memory
	    for(i=0; i<n; i++) free(m[i]);
	    free(m);
	}

	return 0;
}
