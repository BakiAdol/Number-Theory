#include <bits/stdc++.h>

using namespace std;

#define sz 100
int marked[sz/64 + 3];

bool isprime(int num)
{
    return marked[num/64] & (1<<((num>>1)&31));
}

void composit(int num)
{
    marked[num/64] |= (1<<((num>>1)&31));
}

void seive()
{
    for(int i=3;i*i<=sz;i+=2)
    {
        if(!isprime(i))
        {
            for(int j=i*i, k=i<<1;j<sz;j+=k)
            {
                composit(j);
            }
        }
    }
}

int main()
{
    memset(marked,0,sizeof(marked));
    seive();
    cout << 2;
    for(int i=3;i<sz;i+=2) if(!isprime(i)) cout << " " << i;
    cout << endl;

    return 0;
}

