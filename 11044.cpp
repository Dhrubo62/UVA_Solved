/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11044 - "Searching for Nessy"
*/

# include <iostream>
# include <cstdio>
# include <cstring>
# include <cmath>
# include <cstdlib>
# include <algorithm>
# include <cctype>

using namespace std;

int main(void)
{
	int row,column,n,r,c;

	cin >> n;

	while(n)
	{
	    cin >> row >> column;

	    row -= 2;
	    column -= 2;

	    r = row/3;
	    if(row%3)
	    r++;

	    c = column/3;
	    if(column%3)
	    c++;

	    cout << r*c << endl;

	    n--;
	}

	return 0;
}
