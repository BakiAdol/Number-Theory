#include<bits/stdc++.h>

typedef long long int lli;

using namespace std;

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

int main()
{
	cout << AddAndMod(7,5,10);
	return 0;
}
