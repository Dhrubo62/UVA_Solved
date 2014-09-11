/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11244 - "Counting Stars"
*/

# include <iostream>
# include <cstdio>
# include <cstring>
# include <string>
# include <cmath>
# include <cstdlib>
# include <algorithm>
# include <cctype>
# include <vector>
# include <queue>

using namespace std;

int dx[]={1,1,0,-1,-1,0,1,-1};
int dy[]={0,1,1,0,1,-1,-1,-1};

int main()
{
	int r,c,i,j,k,x,y,cnt;
	char **p;

	while(cin>>r>>c && r && c)
	{
	    //memory allocation
	    p=(char **)malloc(r*sizeof(char *));
	    for(i=0; i<r; i++) p[i]=(char *)malloc((c+5)*sizeof(char));

	    //input
	    for(i=0; i<r; i++) cin>>p[i];

	    //check
	    cnt=0;
	    for(i=0; i<r; i++) for(j=0; j<c; j++) if(p[i][j]=='*')
	    {
	        for(k=0; k<8; k++)
	        {
	            x=i+dx[k]; y=j+dy[k];
	            if(x>=0 && x<r && y>=0 && y<c && p[x][y]=='*') break;
	        }
	        if(k==8) cnt++;
	    }

	    //output and memory freeing
	    cout<<cnt<<endl;
	    for(i=0; i<r; i++) free(p[i]);
	    free(p);
	}

	return 0;
}
