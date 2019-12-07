// Complexity O(log n)

int bigMod(int num, int power, int mod)
{
    if(power==0) return 1;
    int v=bigMod(num,power/2,mod);
    v= (v*v)%mod;
    if((power&1)==1) v=(v*num)%mod; // if power is odd
    return v;
}

// more faster
#define ll long long

ll bigMod(ll num, ll base, ll mod)
{
    ll res=1;
    while(base>0)
    {
        if(base&1) res=(res*num)%mod;
        base >>= 1;
        num=(num*num)%mod;
    }
    return res;
}
