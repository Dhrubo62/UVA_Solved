/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 12578
*/

# include <iostream>
# include <cstdio>
# include <cmath>

using namespace std;

# define PI 2*acos (0.0)

int main(void)
  {
	int t;
	cin>>t;
	while(t)
	{
	    double l,d,r,red;
	    cin>>l;

	    d=(l/10)*6;
	    r=(l/10)*2;

	    red=r*r*PI;

	    printf("%0.2lf %0.2lf\n",red,l*d-red);

	    t--;
	}

	return 0;
  }
