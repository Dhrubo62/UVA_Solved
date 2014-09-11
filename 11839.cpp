/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11839 - "Optical Reader"
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

int main()
{
	int n,cnt,i,j,ans;
	double sheet[5];
	string ans_list="ABCDE";

	while(cin>>n && n)
	{
	    for(i=0; i<n; i++)
	    {
	        cin>>sheet[0]>>sheet[1]>>sheet[2]>>sheet[3]>>sheet[4];
	        cnt=0;
	        for(j=0; j<5; j++) if(sheet[j]<=127.0) {cnt++; ans=j;}

	        if(!cnt || cnt>1) cout<<"*"<<endl;
	        else cout<<ans_list[ans]<<endl;
	    }
	}

	return 0;
}
