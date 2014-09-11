/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 10469 - "To Carry or not to Carry"
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
	long long num1 , num2;

	while(cin >> num1 >> num2)
	{
	    num1 = num1 ^ num2;

	    cout << num1 << endl;
	}

	return 0;
}
