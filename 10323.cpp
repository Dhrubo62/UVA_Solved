/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 10323 - "Factorial! You Must be Kidding!!!"
*/

# include <iostream>
# include <cstdio>
# include <cstring>
# include <cmath>
# include <cstdlib>
# include <algorithm>
# include <cctype>

using namespace std;

long long factorial(long long num)
{
    if(num == 1)
    return 1;
    else
    return num*factorial(num-1);
}

int main(void)
{
	long long n;

	while(cin >> n)
	{
	   if(n<0 && !(n%2))
	   cout << "Underflow!\n";
	   else if(n<0 && (n%2))
	   cout << "Overflow!\n";
	   else if(n<8)
	   cout << "Underflow!\n";
	   else if(n>13)
	   cout << "Overflow!\n";
	   else
	   cout << factorial(n) << endl;
	}

	return 0;
}
