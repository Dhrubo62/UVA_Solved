/*
Author: Md. Fahim Mohiuddin
AUST CSE 32 Batch

Problem: UVA - 11730 - Number Transformation
*/

// ----------------- C headers
# include <cstdio>
# include <cstring>
# include <cmath>
# include <cstdlib>
# include <cctype>

// ----------------- C++ headers
# include <iostream>
# include <string>
# include <algorithm>
# include <vector>
# include <queue>
# include <map>

using namespace std;

//------------------ Movements
/*int dx[]={1,-1,0,0}, dy[]={0,0,1,-1};*/ // 4 way movement
/*int dx[]={1,0,-1,0,1,-1,1,-1}, dy[]={0,1,0,-1,1,1,-1,-1};*/ // 8 way movement

vector <int> prime;
bool state[1010];
void sieve()
{
    prime.push_back(2);
    for(long long i=3; i<1010; i+=2)
    {
        if(!state[i])
        {
            prime.push_back(i);
            for(long long j=i*i; j<1010; j+=2*i) state[j]=true;
        }
    }
}

vector <int> adjcnt[1010];
void pre_gen_graph()
{
    for(int i=1; i<=1000; i++)
    {
        int num=i;
        for(int j=0; prime[j]*prime[j]<=num; j++)
        {
            if(!(num%prime[j]))
            {
                adjcnt[i].push_back(prime[j]);
                while(!(num%prime[j])) num/=prime[j];
            }
        }
        if(num>1 && num!=i) adjcnt[i].push_back(num);
    }
}

struct stype
{
    int num,cost;
};

int main()
{
    sieve();
    pre_gen_graph();

    int s,t,csn=0;
    while(cin>>s>>t && s && t)
    {
        int ans=-1;
        queue <stype> q;
        stype push,now;
        bool visited[1010]; memset(visited,false,sizeof visited);

        push.num=s; push.cost=0;
        q.push(push); visited[s]=true;
        while(!q.empty())
        {
            now=q.front(); q.pop();
            int node=now.num;
            if(node==t) {ans=now.cost; break;}

            for(int i=0; i<adjcnt[node].size(); i++)
            {
                int add=adjcnt[node][i];
                if(node+add<=t && !visited[node+add])
                {
                    push.num=node+add; push.cost=now.cost+1;
                    q.push(push); visited[node+add]=true;
                }
            }
        }
        printf("Case %d: %d\n",++csn,ans);
    }

    return 0;
}
