#include <bits/stdc++.h>

using namespace std;

vector<int> primes;

// prime factorization of a single number
// complexity sqrt(n)
vector<long long> factorsOfNumber(long long n)
{
    vector<long long> pFactors;

    while(n%2==0) pFactors.push_back(2),n/=2;

    for(long long i=3;i*i<=n;i+=2)
    {
        while(n%i==0)
        {
            pFactors.push_back(i);
            n/=i;
        }
    }

    if(n>1) pFactors.push_back(n);

    return pFactors;
}

// query prime factorization using seive
// complexity for precalculate min prime divisor O(n log(log n))
vector<int> minPrimeDivisor(1e6+2);
void minPrimeDivisorCalculate()
{
    for(int i=2;i<1e6+2;i++) minPrimeDivisor[i]=i;

    for(int i=2;i*i<1e6+2;i++)
    {
        if(minPrimeDivisor[i]==i)
        {
            for(int j=2;i*j<1e6+2;j++)
            {
                if(minPrimeDivisor[i*j]==i*j) minPrimeDivisor[i*j]=i;
            }
        }
    }
}

// using precalculatem minimum prime number find prime factors
// need complexity O(log(n))
vector<int> factorizeOfANumber(int n)
{
    vector<int> pFactors;

    while(n>1)
    {
        pFactors.push_back(minPrimeDivisor[n]);
        n/=minPrimeDivisor[n];
    }

    return pFactors;
}


// print factors of a number
void printPrimeFactors(vector<long long> pFac, long long num)
{
    cout << "Prime factors of " << num << ": ";
    for(auto &p: pFac) cout << p << " ";
    cout << endl;
}

int main()
{
    long long num = 1e11+1e6;
    printPrimeFactors(factorsOfNumber(num), num);
    
    
    minPrimeDivisorCalculate();

    num = 11;
    printPrimeFactors(factorsOfNumber(num), num);

    num = 560;
    printPrimeFactors(factorsOfNumber(num), num);

    num = 102456;
    printPrimeFactors(factorsOfNumber(num), num);

    num = 1000000;
    printPrimeFactors(factorsOfNumber(num), num);

    return 0;
}
