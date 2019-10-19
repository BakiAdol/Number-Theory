/*
  Number of digits of the factorial of and integer in a certain base
*/

int digitsOfFactorial(int num,int base)
{
    double d=0;
    for(int i=1;i<=num;i++)
    {
        d+=log(i);
    }
    d/=log(base);
    return floor(d)+1;
}

