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


typedef long long int lli;
// What is the a*b mod m where m = 10^15
lli MultiplicationViaAddition(lli a, lli b, lli m)
{
	if(b==1) return a;
	if(b==0) return 0;
	
	lli ans = ((MultiplicationViaAddition(a,b/2,m)%m)*2)%m;

	if(b&1) ans = (ans + (a%m))%m;
	
	return ans;
}

//what is a+b mod m where m is limited but a+b coudn't be store in memory
lli AddAndMod(lli a, lli b, lli m)
{
	if(m-a<=b) return (a+b)%m;
	return b-(m-a);
}

