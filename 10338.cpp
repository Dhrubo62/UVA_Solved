/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 10338 - "Mischievous Children"
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

unsigned long long fact[25];

unsigned long long factorial(int x)
{
    if(x==1) return 1;

    if(fact[x]) return fact[x];
    else
    {
        fact[x]=x*factorial(x-1);
        return fact[x];
    }
}

int main(void)
{
	char str[100];
	int i,n,csn=0,len,cnt[26];
	unsigned long long f;

	cin>>n;
	getchar();
	while(csn<n)
	{
	    gets(str);
	    len=strlen(str);

	    f=factorial(len);

	    for(i=0; i<26; i++) cnt[i]=0;
	    for(i=0; i<len; i++)  cnt[str[i]-'A']++;

	    for(i=0; i<26; i++)  if(cnt[i]>1) f/=factorial(cnt[i]);

	    printf("Data set %d: %llu\n",++csn,f);
	}

	return 0;
}
