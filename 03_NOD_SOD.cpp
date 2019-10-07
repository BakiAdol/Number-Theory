#include <bits/stdc++.h>

using namespace std;

///generate prime numbers from 1 to 1000000
#define MAX 1000000
vector<int> primes;
void primeGenerates()
{
    bool boolPrimes[MAX];
    boolPrimes[0] = 1;
    boolPrimes[1] = 1;
    int limit = sqrt(MAX)+1;
    for(int i=2;i<=limit;i++)
    {
        if(!boolPrimes[i])
        {
            for(int j=2;i*j<=MAX;j++)
            {
                boolPrimes[i*j]=1;
            }
        }
    }
    for(int i=2;i<=MAX;i++)
    {
        if(!boolPrimes[i]) primes.push_back(i);
    }
}

///Runtime O(sqrt(n))
int numberOfDivisor(int n)
{
    int divisor=0;
    if((int)sqrt(n)*(int)sqrt(n)==n)
    {
        divisor++;
    }
    for(int i=1; i*i<n;i++)
    {
        if(n%i==0)
        {
            divisor+=2;
        }
    }
    return divisor;
}

///Another Aproach
int numberofDivisorCount(int n)
{
    int divisors=1,countt;
    for(int i=0;i<(int)primes.size() && n>1; i++)
    {
        if(n%primes[i]==0)
        {
            countt=1;
            while(n%primes[i]==0)
            {
                countt++;
                n/=primes[i];
            }
            divisors*=countt;
        }
    }
    return divisors;
}

///SOD sum of divisor
int sumOfDivisor(int n)
{
    int sum=1,countt;
    for(int i=0;i<(int)primes.size() && n>1;i++)
    {
        if(n%primes[i]==0)
        {
            countt=1;
            while(n%primes[i]==0)
            {
                n/=primes[i];
                countt++;
            }
            sum *= (pow(primes[i],countt)-1)/(primes[i]-1);
        }
    }

    return sum;
}


int main()
{
    primeGenerates();
    cout << numberofDivisorCount(55);
    cout << endl << sumOfDivisor(55);

    return 0;
}

