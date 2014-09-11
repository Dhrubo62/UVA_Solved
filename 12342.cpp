/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 12342 - "Tax Calculator"
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
	long long money,amount,tax,net_tax;
	int t,csn=0;

	cin>>t;
	while(csn<t)
	{
	    cin>>money;
	    tax = 0;

	    //greater than 1180000 with 25%
	    amount = money - 1180000;
	    if(amount<0) amount = 0;
	    money -= amount;
	    net_tax = amount/4;
	    if(amount%4) net_tax++;
	    tax += net_tax;

	    //greater than 880000 with 20%
	    amount = money - 880000;
	    if(amount<0) amount = 0;
	    money -= amount;
	    net_tax = amount/5;
	    if(amount%5) net_tax++;
	    tax += net_tax;

	    //greater than 480000 with 15%
	    amount = money - 480000;
	    if(amount<0) amount = 0;
	    money -= amount;
	    amount *= 3;
	    net_tax = amount/20;
	    if(amount%20) net_tax++;
	    tax += net_tax;

	    //greater than 180000 with 10%
	    amount = money - 180000;
	    if(amount<0) amount = 0;
	    net_tax = amount/10;
	    if(amount%10) net_tax++;
	    tax += net_tax;

	    if(tax>0 && tax<2000) tax = 2000;

	    printf("Case %d: %lld\n",++csn,tax);
	}

	return 0;
}
