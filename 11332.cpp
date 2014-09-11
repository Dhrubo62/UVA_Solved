/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11332
*/

# include <iostream>
# include <cstdio>

using namespace std;

int main(void)
  {
	long long num,temp;
	char str[100];
	while(cin>>num)
	{
	    if(!num)
	    break;

	    while(1)
	    {
	        if(num<10)
	        break;

	        temp=num;
	        num=0;
	        while(temp)
	        {
	            num+=temp%10;
	            temp/=10;
	        }
	    }
	    cout<<num<<endl;
	}

	return 0;
  }
