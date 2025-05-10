#include<bits/stdc++.h>
using namespace std;
/// Z algorithm hocche i position theke shuru kore maximum koto subarray length paoya jay jeta toto lenght er
///prefix er soman hobe
///   a b c a b c
 ///  0 0 1 3 0 0
 /// 3 eta maximum   subarray equal paoya jay jeta abar prefix

vector<long long>Z(string &s) ///time complexity O(n)
{

    long long n  =s.size();
    vector<long long> z(n);
    long long l = 0, r = 0;
    for(int i =1;i<n;i++)
    {
        if(i<r)
        {
            z[i] = min(r - i, z[i - l]);
        }
        while(i+z[i]<n && s[z[i]]==s[i+z[i]])
        {
            z[i]++;
        }
        if(i+z[i]>r)
        {
            l = i;
            r =i+z[i];
        }
    }
    return z;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long tt=1;
    ///cin>>tt;
    while(tt--)
    {
       string s;
       cin>>s;
       vector<long long>z=Z(s);
       for(int i=0;i<z.size();i++)
       {
           cout<<z[i]<<" ";
       }

    }
    return 0;
}



