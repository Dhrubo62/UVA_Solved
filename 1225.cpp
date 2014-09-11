/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 1225 - "Digit Counting"
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
	int n,num;

	cin>>n;
	while(n)
	{
	    string str="";
	    char number[100];

	    cin>>num;
	    for(int i=1; i<=num; i++)
	    {
	        sprintf(number,"%d",i);
	        str+=number;
	    }

	    int cnt[10]; for(int i=0; i<10; i++) cnt[i]=0;
	    int len=str.size();

	    for(int i=0; i<len; i++) cnt[str[i]-'0']++;

	    cout<<cnt[0];
	    for(int i=1; i<=9; i++) cout<<" "<<cnt[i];
	    cout<<endl;

	    n--;
	}

	return 0;
}
