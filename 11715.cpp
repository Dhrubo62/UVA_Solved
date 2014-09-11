/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11715
*/

# include <iostream>
# include <cstdio>
# include <cstring>
# include <cmath>
# include <cstdlib>
# include <algorithm>

using namespace std;

int main(void)
{
	int i,cs=0;
	double u,v,a,t,s;

	while (cin >> i && i)
	{
	    if (i==1)
	    {
	        cin >> u >> v >> t;
	        s = ((u+v)/2)*t;
	        a = (v-u)/t;
	        printf("Case %d: %0.3lf %0.3lf\n",++cs,s,a);
	    }
	    else if (i==2)
	    {
	        cin >> u >> v >> a;
	        s = (v*v-u*u)/(2*a);
	        t = (v-u)/a;
	        printf("Case %d: %0.3lf %0.3lf\n",++cs,s,t);
	    }
	    else if (i==3)
	    {
	        cin >> u >> a >> s;
	        v = pow((u*u+2*a*s),0.5);
	        t = (v-u)/a;
	        printf("Case %d: %0.3lf %0.3lf\n",++cs,v,t);
	    }
	    else if(i==4)
	    {
	        cin >> v >> a >> s;
	        u = pow((v*v-2*a*s),0.5);
	        t = (v-u)/a;
	        printf("Case %d: %0.3lf %0.3lf\n",++cs,u,t);
	    }
	}

	return 0;
}
