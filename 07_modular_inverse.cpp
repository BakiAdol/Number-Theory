#include<bits/stdc++.h>

using namespace std;

/**
 * Modular Multiplicative Inverse
 * 
 * Multiplicative inverse of and integer a modulo m is an integer x such that ax = 1 (mod m)
 * This is equivalent to x = 1/a (mod m)
 * The multiplicative inverse of a modulo m exist iff a and m are coprime(gcd(a,m)==1).
 * 
 * */
 
// Brute Force approach find modulo multiplicative inverse
int modInverse(int a, int m)
{
	a%=m;
	for(int x=1;x<m;x++)
	{
		if((a*x)%m==1) return x;
	}
	return -1;
}

/**
 * Fermat's Little Theorem
 * a^(m-1) = 1 (mod m) where m is prime and also a and m are coprime
 * This is equvalent to a*a^(m-2) = 1 (mod m); So we can say that the multiplicative inverse of a is x(x = a^(m-2));
 * */
// Complexity log(p) 
int bigMod(int a, int p, int m)
{
	if(p==0) return 1;
	int v = bigMod(a,p/2,m);
	v = (v*v)%m;
	if(p&1) v = (v*a)%m;
	
	return v;
}

/**
 * a^x = 1 (mod m) [x=m-1] where m is prime and also a and m are coprime, here x is not an coincident, x is count co-primes
 * of m between 1 to m-1. So we can calculate modulo invers of a mod m using Euler's Totient Theorem.
 * 
 * Euler's Totient Theorem = a^phi(m) = 1 mod m
 * So here inverse modulo of a mod m = a^phi(m)-1) where [a*(a^phi(m)-1) = 1 mod m]
 * */

int modInverseEuler(int a, int m)
{
	int phiOfM = 0;
	for(int i=2;i<m;i++)
	{
		if(__gcd(i,m)==1) phiOfM++;
	}
	
	return bigMod(a,phiOfM,m);
}

/**
 * We need 1/a mod b. Let 1/a mod b = x
 * So ax = 1 (mod b) => ax + by = 1 (mod b) [by % b = 0]
 * Here ax + by = c is linear diophentine equetion, for this equation solution always exist 
 * iff c%gcd(a,b)==0, This is called bezout's identity
 * So, we can find the value of x and y using egcd and x is the inverse modulo of a
 * Let's concider a equetion 1x + 0y = 1, Here one solution is x=1, y=0;
 * Let's find gcd(a,b) = gcd(4,13)
 * 	a	b
 * 	4	13
 * 	13	4
 * 	4	1
 * 	1	0
 * We know the solution for {1,0} and then we can find the solution of previous step
 * Current step  ax + by = 1
 * Previous step bx1 + (a mod y1) = 1
 * => bx1 + (a-[a/b]*b)y1=1 
 * => bx1 + ay1 - [a/b]*b*y1 = 1 
 * => ay1 + b(x1-[a/b]*y1)=1
 * So x = y1, y=x1-[a/b]*y1
 * 
 * 1*1 + 0*0 = 1 [a=1,b=0,x=1,y=0]
 * 4*0 + 1*1 = 1 [a=4,b=1,x=0,y=1-4*0=1]
 * 13*1 + 4*-3 = 1 [a=13,b=4,x=1,y=0-3*1=-3]
 * 4(-3) + 13*1 = 1 [a=4,b=13,x=-3,y=1-0*-3=1]
 * x= -3 mod 13 = (-3+13)%13 = 10
 * */

void egcd(int a, int b, int &x, int &y)
{
	if(b==0)
	{
		x=1;
		y=0;
		return;
	}
	
	int x1,y1;
	egcd(b,a%b,x1,y1);
	x=y1;
	y=x1 - y1*(a/b);
}

int main()
{
	cout << "Brute Force approach : " << modInverse(4,13) << endl;
	cout << "Using Fermat's little theorem : " << bigMod(4,13-2,13) << endl;
	cout << "Euler's Totient Theorem : " << modInverseEuler(4,13) << endl;

	int x,y;
	egcd(4,13,x,y);
	cout << "Extended Euclidean Algorithm : " <<(x+13)%13 <<endl;
	
	return 0;
}


