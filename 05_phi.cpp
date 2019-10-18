/*
  phi(n) = n ( 1 - 1/p1 ) ( 1 - 1/p2 ).....( 1 - 1/pk )
*/

/// find phi for number n

int phi(int n)
{
    int res=n;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            while(n%i==0) n/=i;
            res-=res/i; // n(1-1/p)
        }
    }
    if(n>1) res-=res/n;
    return res;
}
//...............................................

// Generate phi..................

int phi[10000];
bool mark[10000];

void generatePhi(int n)
{
    for(int i=1;i<=n;i++) phi[i]=i;
    mark[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(!mark[i]) // i is prime
        {
            for(int j=i;j<n;j+=i)
            {
                phi[j]-=phi[j]/i; // n(1-1/p)
            }
        }
    }
}

