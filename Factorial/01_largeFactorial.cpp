#include <bits/stdc++.h>

using namespace std;

#define MAX 1000

int fac[MAX];

int multiply(int num,int facSize)
{
    int carry=0;
    int mul;
    for(int i=0;i<facSize;i++)
    {
        mul=(fac[i]*num)+carry;
        fac[i]=mul%10;
        carry=mul/10;
    }
    while(carry>0)
    {
        fac[facSize++]=carry%10;
        carry/=10;
    }
    return facSize;
}

void factorial(int n)
{
    fac[0]=1;
    int facSize=1;
    for(int i=2;i<=n;i++)
    {
        facSize = multiply(i,facSize);
    }
    for(int i=facSize-1;i>=0;i--) cout << fac[i];
    cout << endl;
}

int main()
{
    factorial(100);

    return 0;
}
