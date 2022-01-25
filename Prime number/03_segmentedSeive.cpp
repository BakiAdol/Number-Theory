#include <bits/stdc++.h>

using namespace std;
/**
 * Generate all primes between L to R
 * L<=R and R<10^12 and R-L = 10^6
 */

vector<long> primes;
void primeGenerate() // generate prime  less or equal to sqrt(10^12)
{
    int maxlen = 1e6+5;
    bool isPrime[maxlen];

    for(int i=0;i<maxlen;i++) isPrime[i]=true;

    primes.push_back(2);

    for(int i=3;i*i<maxlen;i++)
    {
        if(isPrime[i])
        {
            for(int j=i*i;j<maxlen;j+=i*2)
            {
                isPrime[j]=false;
            }
        }
    }

    for(int i=3;i<maxlen;i+=2)
    if(isPrime[i])
    primes.push_back(i);
}

vector<long long> segPrimes;
// segmented seive
void segmentedSeive(long long L, long long R)
{
    long long maxlen = R-L+5;
    bool isPrime[maxlen];
    for(long long i=0;i<maxlen;i++) isPrime[i]=true;

    for(int i=0;i<(int)primes.size() and primes[i]*primes[i]<=R;i++)
    {
        long long p = primes[i];
        long long num = (L/p)*p;
        if(num<L) num+=p;

        for(long long numl = num; numl<=R;numl+=p)
        {
            isPrime[numl-L]=false;
        }

        if(p==num) isPrime[p-L]=true;
    }
    for(long long pos=max((long long)2,L);pos<R;pos++)
    if(isPrime[pos-L])
    segPrimes.push_back(pos);
}

int main()
{
    primeGenerate();

    long long L = 1e12;
    long long R = 1e12+1e3;

    segmentedSeive(L,R);

    for(auto x:segPrimes) cout <<x << " ";
    
    return 0;
}
