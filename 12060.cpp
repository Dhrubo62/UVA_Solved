/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 12060 - "All Integer Average"
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

int digit(int n)
{
    int cnt=0;

    while(n)
    {
        cnt++;  n/=10;
    }

    return cnt;
}

int main(void)
{
	int n,num,sum,csn=0,i;
	bool neg;

	while(cin>>n && n)
	{
	    sum=0;
	    neg=false;

	    //inputing numbers and making sum
	    for(i=0; i<n; i++)
	    {
	        cin>>num;   sum+=num;
	    }
	    if(sum<0)
	    {
	        neg=true;   sum *= -1;
	    }

        int g=__gcd(sum,n);
        sum /= g;
        n /= g;

        int a=sum/n;
        sum %= n;

        //calculating spaces to be printed
        int one=digit(n)-digit(sum)+digit(a); if(neg) one +=2; //first line
        int third=digit(a); if(neg) third += 2; //third line

        //printing process
        printf("Case %d:\n",++csn);
        if(!sum)
        {
            if(neg) cout<<"- ";
            cout<<a<<endl;
        }
        else
        {
            //first line
            for(i=0; i<one; i++) cout<<" "; //space print
            cout<<sum<<endl; //number print

            //second line
            if(neg) printf("- ");
            if(a) cout<<a;
            for(i=0; i<digit(n); i++) cout<<"-"; //hiphen print
            cout<<endl;

            //third line
            for(i=0; i<third; i++) cout<<" "; //space print
            cout<<n<<endl;
        }
	}

	return 0;
}
