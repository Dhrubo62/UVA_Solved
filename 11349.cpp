/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11349 - "Symmetric Matrix"
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
	long long **mat,n,csn,c=0,i,j,m;
	char str[100];
	bool sym,neg;

	cin>>csn;

	while(c<csn)
	{
	    getchar();
	    gets(str);

	    n=0;
	    for(i=4; str[i]; i++) n = n*10 + str[i] - '0';

	    //memory allocation
	    mat=(long long **)malloc(n*sizeof(long long *));
	    for(i=0; i<n; i++) mat[i]=(long long *)malloc(n*sizeof(long long));

	    //input
	    neg=false;
	    for(i=0; i<n; i++)
	    {
	        for(j=0; j<n; j++)
	        {
	            cin>>mat[i][j];
	            if(mat[i][j]<0) neg=true;
	        }
	    }

	    //initial printing
	    printf("Test #%lld: ",++c);

	    //negative check
	    if(neg)
	    {
	        cout<<"Non-symmetric."<<endl;

	        for(i=0; i<n; i++) free(mat[i]);
            free(mat);

            continue;
	    }

	    //symmetric check
	    m = n/2;
	    if(!(n%2)) m--;
	    sym=true;
	    for(i=0; i<=m; i++)
	    {
	        for(j=0; j<n; j++)
	        {
	            if(mat[i][j] != mat[n-1-i][n-1-j])
	            {
	                sym=false;
	                break;
	            }
	        }
	    }

	    //result print
	    if(sym) cout<<"Symmetric."<<endl;
	    else cout<<"Non-symmetric."<<endl;

	    //freeing dinamicly allocated memory
	    for(i=0; i<n; i++) free(mat[i]);
	    free(mat);
	}

	return 0;
}
