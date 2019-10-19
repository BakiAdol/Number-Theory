
/*
* gcd
* Initialy it start with (a,b) 
* Then (b,r) where r=a%b
* Then (b,r) where r=b%r
* Then (b,r) where r=b%r .....
* Here b*r < 1/2(a*b)
* That means the product of two numbers in the function decrease by half every time.
*/
///Time complexity O(logn ab)

int gcd(int a, int b)
{
    return a%b == 0 ? b : gcd(b, a%b);
}


/*
    Extended GCD
    ax+by=gcd(a,b)
*/

int exgcd(int a, int b, int &x, int &y)
{
    if(a==0)
    {
        x=0;
        y=1;
        return b;
    }

    int x1,y1;
    int d=exgcd(b%a,a,x1,y1);

    x=y1-(b/a)*x1;
    y=x1;
    return d;
}
