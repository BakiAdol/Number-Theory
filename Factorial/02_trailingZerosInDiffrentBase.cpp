/*
  Number of trainling zeros in base b of n!
*/

#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> baseFactor(int base)
{
    vector<pair<int,int>> fac;
    for(int i=2;base>1;i++)
    {
        if(base%i==0)
        {
            int power=0;
            while(base%i==0)
            {
                base/=i;
                power++;
            }
            fac.push_back(make_pair(i,power));
        }

    }
    return fac; // fac.first = factor and fac.second = power
}

int numberOfTrailngZeros(int num, int base)
{
    vector<pair<int,int>> fac=baseFactor(base);
    int res=INT_MAX,ans;
    for(int i=0;i<(int)fac.size();i++)
    {
        ans=0;
        int f=fac[i].first;
        int ff=f;
        while(num>=f)
        {
            ans+=num/f;
            f*=ff;
        }
        res=min(res,ans/fac[i].second);
    }
    return res;
}

int main()
{
    cout << numberOfTrailngZeros(25,10) << endl;
    cout << numberOfTrailngZeros(25,8) << endl;
    return 0;
}

