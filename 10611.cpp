/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 10611 - "The Playboy Chimp"
*/

// ----------------- C headers
# include <cstdio>
# include <cstring>
# include <cmath>
# include <cstdlib>
# include <cctype>

// ----------------- C++ headers
# include <iostream>
# include <string>
# include <algorithm>
# include <vector>
# include <queue>

//------------------ Movements
/*int dx[]={1,-1,0,0}, dy[]={0,0,1,-1};*/ // 4 way movement
/*int dx[]={1,0,-1,0,1,-1,1,-1}, dy[]={0,1,0,-1,1,1,-1,-1};*/ // 8 way movement


using namespace std;

int main()
{
	int n,i,age,q,low,high;
	vector <int> list;

	cin>>n;
	for(i=0; i<n; i++) {cin>>age; list.push_back(age);}

	cin>>q;
	while(q--)
	{
	    cin>>age;
	    low=high=-1;

	    for(i=0; i<n; i++)
	    {
	        if(list[i]<age) low=list[i];
	        else if(list[i]>age) {high=list[i]; break;}
	    }

	    if(low==-1) cout<<"X"; else cout<<low;
	    cout<<" ";
	    if(high==-1) cout<<"X"; else cout<<high;
	    cout<<endl;
	}

	return 0;
}
