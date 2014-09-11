/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 914 - "Jumping Champion"
*/

# include <iostream>
# include <cstdio>
# include <cstring>
# include <string>
# include <cmath>
# include <cstdlib>
# include <algorithm>
# include <cctype>
# include <vector>
# include <queue>

using namespace std;

bool prime[1000007];
vector <int> prime_list;
int ind;
void sieve()
{
    prime_list.push_back(2);
    for(long long i=3; i<1000007; i+=2)
    {
        if(!prime[i])
        {
            prime_list.push_back(i);
            for(long long j=i*i; j<1000007; j+=2*i) prime[j]=1;
        }
    }
    ind=prime_list.size();
}

struct stype
{
    int num,cnt;
};

int compare(stype a,stype b)
{
    return a.cnt>b.cnt;
}

int main()
{
    sieve();

    int t;
    cin>>t;
    while(t)
    {
        t--;

        int start,end,diff,i,j;
        vector <stype> diff_list;

        cin>>start>>end;
        if(start>end)
        {
            int temp=start;
            start=end;
            end=temp;
        }

        for(i=0; i<ind; i++)
        {
            if(prime_list[i]>end) break;
            else if(prime_list[i]>=start && prime_list[i+1]<=end)
            {
                diff=prime_list[i+1]-prime_list[i];
                for(j=0; j<diff_list.size(); j++) if(diff_list[j].num==diff) break;
                if(j==diff_list.size())
                {
                    stype push;
                    push.num=diff; push.cnt==1; diff_list.push_back(push);
                }
                else diff_list[j].cnt++;
            }
        }

        if(!diff_list.size()) cout<<"No jumping champion"<<endl;
        else
        {
            sort(diff_list.begin(),diff_list.end(),compare);
            if(diff_list.size()>1 && diff_list[0].cnt==diff_list[1].cnt) cout<<"No jumping champion"<<endl;
            else printf("The jumping champion is %d\n",diff_list[0].num);
        }
    }

	return 0;
}
