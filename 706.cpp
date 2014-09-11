/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 706 - "LC-Display"
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
	int n,i,j,len;
	string str,top,first,mid,second,bottom;
	bool first_one;

	while(cin>>n>>str)
	{
	    if(!n && str=="0") break;

	    top=first=mid=second=bottom="";

	    len=str.size();
	    first_one=true;
	    for(i=0; i<len; i++)
	    {
            //space print
            if(first_one) first_one=false;
            else
            {
                top+=" "; first+=" "; mid+=" "; second+=" "; bottom+=" ";
            }

            //initial space for top, mid and bottom
            top+=" "; mid+=" "; bottom+=" ";

            //lcd block construction
            //top
            if(str[i]=='2'||str[i]=='3'||str[i]=='5'||str[i]=='6'||str[i]=='7'||str[i]=='8'||str[i]=='9'||str[i]=='0')
            {
                for(j=0; j<n; j++) top+="-";
            }
            else for(j=0; j<n; j++) top+=" ";

            //first
            if(str[i]=='1'||str[i]=='2'||str[i]=='3'||str[i]=='7') first+=" ";
            else first+="|";

            for(j=0; j<n; j++) first+=" ";

            if(str[i]=='5'||str[i]=='6') first+=" ";
            else first+="|";

            //mid
            if(str[i]=='1'||str[i]=='7'||str[i]=='0') for(j=0; j<n; j++) mid+=" ";
            else for(j=0; j<n; j++) mid+="-";

            //second
            if(str[i]=='1'||str[i]=='3'||str[i]=='4'||str[i]=='5'||str[i]=='7'||str[i]=='9') second+=" ";
            else second+="|";

            for(j=0; j<n; j++) second+=" ";

            if(str[i]=='2') second+=" ";
            else second+="|";

            //bottom
            if(str[i]=='1'||str[i]=='4'||str[i]=='7') for(j=0; j<n; j++) bottom+=" ";
            else for(j=0; j<n; j++) bottom+="-";

            //finishing space for top, mid and bottom
            top+=" "; mid+=" "; bottom+=" ";
	    }

	    //printing
	    cout<<top<<endl;
	    for(i=0; i<n; i++) cout<<first<<endl;
	    cout<<mid<<endl;
	    for(i=0; i<n; i++) cout<<second<<endl;
	    cout<<bottom<<endl<<endl;
	}

	return 0;
}
