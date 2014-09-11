/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11462 - "Age Sort"
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
	char age[2000001];
	int n;

	while(cin >> n && n)
	{
	    int i=0;
	    while(n)
	    {
	        scanf("%d",&age[i]);

	        if(age[i]>=1 && age[i]<=100) i++;

	        n--;
	    }

	    sort(age,age+i);

	    bool first=true;
	    for(int j=0; j<i; j++)
	    {
	        if(first)
	        first = false;
	        else
	        printf(" ");

	        printf("%d",age[j]);
	    }

	    cout << endl;
	}

	return 0;
}
