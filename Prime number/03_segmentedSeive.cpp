#include <bits/stdc++.h>

using namespace std;

#define mx 31700
vector<int> primes;

void generatePrimes()
{
    bool mark[mx];
    memset(mark,0,sizeof(mark));
    for(int i=3;i<mx;i+=2)
    {
        if(!mark[i])
        {
            for(int j=i*i;j<=mx;j+=i)
            {
                mark[j]=1;
            }
        }
    }
    primes.push_back(2);
    for(int i=3;i<mx;i+=2) if(!mark[i]) primes.push_back(i);
}

void segmentSevive(long long start, long long endd)
{
    int sz=endd-start+1;
    bool mark[sz];
    memset(mark,0,sizeof(mark));
    if(start==1) mark[0]=1;
    for(int i=0;primes[i]*primes[i]<=endd;i++)
    {
        long long p=primes[i];
        long long startNum=(start/p)*p;
        if(startNum<start) startNum+=p;

        for(long long ind=startNum;ind<=endd;ind+=p)
        {
            mark[ind-start]=1;
        }
        if(startNum==p) mark[startNum-start]=0;
    }
    for(int i=0;i<sz;i++) if(!mark[i]) cout << start+i << endl;
}

int main()
{
    generatePrimes();
    segmentSevive(50,100);
    return 0;
}

