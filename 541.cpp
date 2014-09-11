/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 541 - "Error Correction"
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
	bool **m,ok,changed;
	int n,i,j,k,sum,a,b;

	while(cin>>n && n)
	{
	    //memory allocation
	    m=(bool **)malloc(n*sizeof(bool *));
	    for(i=0; i<n; i++) m[i]=(bool *)malloc(n*sizeof(bool));

        //input
        for(i=0; i<n; i++) for(j=0; j<n; j++) cin>>m[i][j];

        //before everything
        ok=true; changed=false;

        //checking rows
        for(i=0; i<n; i++)
        {
            sum=0; for(j=0; j<n; j++) sum+=m[i][j];
            if(sum%2)
            {
                if(changed) {cout<<"Corrupt"<<endl; goto escape;}

                //else, try to change
                ok=false;
                for(j=0; j<n && !ok; j++)
                {
                    sum=0; for(k=0; k<n; k++) sum+=m[k][j];
                    if(sum%2)
                    {
                        ok=true; changed=true;
                        a=i+1; b=j+1;
                        if(m[i][j]) m[i][j]=0;
                        else m[i][j]=1;
                    }
                }
                if(!ok) {cout<<"Corrupt"<<endl; goto escape;}
            }
        }

        //checking columns
        for(j=0; j<n; j++)
        {
            sum=0; for(i=0; i<n; i++) sum+=m[i][j];
            if(sum%2)
            {
                if(changed) {cout<<"Corrupt"<<endl; goto escape;}

                //else, try to change
                ok=false;
                for(i=0; i<n && !ok; i++)
                {
                    sum=0; for(k=0; k<n; k++) sum+=m[i][k];
                    if(sum%2)
                    {
                        ok=true; changed=true;
                        a=i+1; b=j+1;
                        if(m[i][j]) m[i][j]=0;
                        else m[i][j]=1;
                    }
                }
                if(!ok) {cout<<"Corrupt"<<endl; goto escape;}
            }
        }

        //if everything has been ok
        if(changed) printf("Change bit (%d,%d)\n",a,b);
        else cout<<"OK"<<endl;

        escape:
	    //freeing memory
	    for(i=0; i<n; i++) free(m[i]);
	    free(m);
	}

	return 0;
}
