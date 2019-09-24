//--------------------------Generate Prime Numbers-----------------------------------
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

//-----------------------------------------------------------------------------------


//---------------------------Test a number is prime or not---------------------------

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
