
//---------------------------Test a number is prime or not----------------------------------------
/*
* Time Complexity O(squere root of n)
*/

bool primeTest(int n)
{
    if(n<2) return false;
    int limit = sqrt(n);
    for(int i=2;i<=limit;i++)
    {
        if(n%i==0)
        {
            return false;
        }
    }
    return true;
}

//--------------------------------------------------------------------------------------------------

/*
* Using Eratosthenes's Sieve
* Time Complexity O(n log log n)
* Here the number of iteration O(n) + Summation of n/p; where p is prime number and n>=p
* From Merten's Second Theorem, Summation of n/p = log log n + O(1)
*/
//-----------------------------------Generate Prime Numbers----------------------------------------
void prime()
{
    int range=100001;
    int primes[range];
    primes[0]=0,primes[1]=0;
    for(int i=2;i<range;i++)
    {
        primes[i]=1;
    }
    for(int i=2;i<range;i++)
    {
        if(primes[i])
        {
            for(int j=2;i*j<range;j++)
            {
                primes[i*j]=0;
            }
        }
    }
    for(int i=0;i<range;i++)
    {
        if(primes[i])
        {
            cout << i << endl;
        }
    }
}

//--------------------------------------------------------------------------------------------------

///------------------------------------------ Optimeze seive ---------------------------------------
void prime()
{
	/**
	 * 
	 *  -> only 2 is even number that is prime, so we check only odd numbers
	 *  -> Suppose We check for odd=3, so next cut number is odd*2=6, here 6 is even
	 * 	   so it's completely unnecessary. so we start tmp=odd, odd=tmp*tmp and increase
	 *     odd+=tmp*2, then we get every time odd number.
	 * 
	 * */
	
	long long int range=1000001;
	bool check[range];
	vector<int> primes;
	
	primes.push_back(2);
	
	for(long long int i=3;i<range;i+=2)
	{
		if(check[i]==0)
		{
			primes.push_back(i);
			
			for(long long int j=i*i;j<range;j+=i*2) check[j]=1;
		}
	}
	
	for(int i=0;i<10;i++) cout << primes[i] << endl;
}
///-------------------------------------------------------------------------------------------------

//---------------------------------------Prime Factorization----------------------------------------

void primeFactorization(int n)
{
    int range=100001;
    int primes[range];
    int primeFactor[range];
    for(int i=2;i<range;i++)
    {
        primes[i]=1;
    }
    for(int i=2;i<range;i++)
    {
        if(primes[i])
        {
            primeFactor[i]=i;
            for(int j=2;i*j<range;j++)
            {
                primes[i*j]=0;
                if(primeFactor[i*j]==0)
                {
                    primeFactor[i*j]=i;
                }
            }
        }
    }
    while(n!=1)
    {
        cout << primeFactor[n] << endl;
        n/=primeFactor[n];
    }
}

