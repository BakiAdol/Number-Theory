#include <bits/stdc++.h>

using namespace std;

// check a number is prime or not
// complexity O(sqrt(n))
bool isPrime(int n)
{
    if(n<2) return false;

    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0) return false;
    }
    return true;
}

// generate prime numbers
// complexity O(n log(log(n)))
vector<int> primes;
void primeGenerate()
{
    bool isPrime[105];
    for(int i=2;i<101;i++)
    {
        if(isPrime[i]==0)
        {
            for(int j=2;i*j<101;j++)
            {
                isPrime[i*j]=1;
            }
        }
    }
    for(int i=2;i<101;i++)
    if(isPrime[i]==0) 
    primes.push_back(i);
}

// Optimized prime generation
// there are only 2 is even prime, so we check for only odd numbers
void primeGenerateOptimized()
{
    primes.push_back(2);
    bool isPrime[105];
    for(int i=3;i<101;i+=2)
    {
        if(isPrime[i]==0)
        {
            // start erasing from i*i, because all numbers between
            // i and i*i already erased
            for(int j=i*i;j<101;j+=i*2)
            {
                // i and j both are odd now
                // so if we add i with j then j will be even (odd+odd=even)
                // se we add i+i with j then j will be odd (odd + (odd+odd=even)) 
                isPrime[j]=1;
            }
        }
    }
    for(int i=3;i<101;i+=2)
    if(isPrime[i]==0) 
    primes.push_back(i);
}


int main()
{
    cout << "97 is a " << (isPrime(97) ? "Prime" : "Nonprime") << " number." << endl;

    primeGenerate();
    for(auto &prime : primes)
    {
        cout << prime << " ";
    }
    cout << endl;

    primes.clear();

    primeGenerateOptimized();
    for(auto &prime : primes)
    {
        cout << prime << " ";
    }
    cout << endl;


    return 0;
}
