// Complexity O(log n)

int bigMod(int num, int power, int mod)
{
    if(power==0) return 1;
    int v=bigMod(num,power/2,mod);
    v= (v*v)%mod;
    if((power&1)==1) v=(v*num)%mod; // if power is odd
    return v;
}

