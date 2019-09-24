///Time complexity O(logn ab)
/*
* Initialy it start with (a,b) 
* Then (b,r) where r=a%b
* Then (b,r) where r=b%r
* Then (b,r) where r=b%r .....
* Here b*r < 1/2(a*b)
* That means the product of two numbers in the function decrease by half every time.
*/

int gcd(int a, int b)
{
    return a%b == 0 ? b : gcd(b, a%b);
}
