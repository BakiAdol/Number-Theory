/*
    All numbers(1 to 100) are not divided by 2,3,5,7
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int two,three,five,seven,res;
    two=100/2; // 50 numbers(1 to 100 inclusive) are divided by 2
    three=100/3; // 33 numbers(1 to 100 inclusive) are divided by 3
    five=100/5; // 20 numbers(1 to 100 inclusive) are divided by 5
    seven=100/7; // 14 numbers(1 to 100 inclusive) are divided by 7
    // 50+33+20+14=117 numbers are divided by 2,3,5,7
    res=two+three+five+seven;
    // but in 120 numbers some number are common in divided by 2 and 3
    // so we need to subtract number those are divided by 2 and 3 or 2*3=6
    // Same way 2*3=6,2*5=10,2*7=14,3*5=15,3*7=21,5*7=35
    res-=100/6;
    res-=100/10;
    res-=100/14;
    res-=100/15;
    res-=100/21;
    res-=100/35;
    // Now 2*3*5=30 is a number between 1 to 100 is add for 2,3,5 and subtract for
    // 6,10,15 here we don't count 30, so we need to add some numbers which are
    // divided by 2*3*5=30, 2*3*7=42, 3*5*7=105, 2*5*7=70
    res+=100/30;
    res+=100/42;
    res+=100/105;
    res+=100/70;
    cout << 100-res << endl;

    /*
        This is from set concept
        U = union
        I = intersect

        s(a U b) = s(a) + s(b) - s(a I b)

        s(a U b U c) = s(a)+s(b)+s(c) - s(a I b) - s(a I c) - s(b I c) + s(a I b I c)

        s(a U b U c U d) = s(a)+s(b)+s(c)+s(d) -
                           s(a I b) - s(a I c) - s(a I d) - s(b I c) - s(b I d) - s(d I d)
                           +s(a I b I c)+s(a I b I d)+s(b I c I d)+s(a I c I d)
                           -s(a I b I c I d)
    */

    return 0;
}
